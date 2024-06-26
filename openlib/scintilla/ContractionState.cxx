// Scintilla source code edit control
/** @file ContractionState.cxx
 ** Manages visibility of lines for folding and wrapping.
 **/
// Copyright 1998-2007 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#include <cstddef>
#include <cassert>
#include <cstring>

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>

#include "Platform.h"

#include "Position.h"
#include "UniqueString.h"
#include "SplitVector.h"
#include "Partitioning.h"
#include "RunStyles.h"
#include "SparseVector.h"
#include "ContractionState.h"

using namespace Scintilla;

namespace {

class ContractionState final : public IContractionState {
	// These contain 1 element for every document line.
	std::unique_ptr<RunStyles<Sci::Line, char>> visible;
	std::unique_ptr<RunStyles<Sci::Line, char>> expanded;
	std::unique_ptr<RunStyles<Sci::Line, int>> heights;
	std::unique_ptr<SparseVector<UniqueString>> foldDisplayTexts;
	std::unique_ptr<Partitioning<Sci::Line>> displayLines;
	Sci::Line linesInDocument;

	void EnsureData();

	bool OneToOne() const noexcept {
		// True when each document line is exactly one display line so need for
		// complex data structures.
		return visible == nullptr;
	}

	void InsertLine(Sci::Line lineDoc);
	void DeleteLine(Sci::Line lineDoc);

public:
	ContractionState() noexcept;
	// Deleted so ContractionState objects can not be copied.
	ContractionState(const ContractionState &) = delete;
	void operator=(const ContractionState &) = delete;
	ContractionState(ContractionState &&) = delete;
	void operator=(ContractionState &&) = delete;
	~ContractionState();

	void Clear() noexcept override;

	Sci::Line LinesInDoc() const override;
	Sci::Line LinesDisplayed() const override;
	Sci::Line DisplayFromDoc(Sci::Line lineDoc) const override;
	Sci::Line DisplayLastFromDoc(Sci::Line lineDoc) const override;
	Sci::Line DocFromDisplay(Sci::Line lineDisplay) const override;

	void InsertLines(Sci::Line lineDoc, Sci::Line lineCount) override;
	void DeleteLines(Sci::Line lineDoc, Sci::Line lineCount) override;

	bool GetVisible(Sci::Line lineDoc) const override;
	bool SetVisible(Sci::Line lineDocStart, Sci::Line lineDocEnd, bool isVisible) override;
	bool HiddenLines() const override;

	const char *GetFoldDisplayText(Sci::Line lineDoc) const override;
	bool GetFoldDisplayTextShown(Sci::Line lineDoc) const override;
	bool SetFoldDisplayText(Sci::Line lineDoc, const char *text) override;

	bool GetExpanded(Sci::Line lineDoc) const override;
	bool SetExpanded(Sci::Line lineDoc, bool isExpanded) override;
	Sci::Line ContractedNext(Sci::Line lineDocStart) const override;

	int GetHeight(Sci::Line lineDoc) const override;
	bool SetHeight(Sci::Line lineDoc, int height) override;

	void ShowAll() override;

	void Check() const;
};

ContractionState::ContractionState() noexcept : linesInDocument(1) {
}

ContractionState::~ContractionState() {
	Clear();
}

void ContractionState::EnsureData() {
	if (OneToOne()) {
		visible = std::make_unique<RunStyles<Sci::Line, char>>();
		expanded = std::make_unique<RunStyles<Sci::Line, char>>();
		heights = std::make_unique<RunStyles<Sci::Line, int>>();
		foldDisplayTexts = std::make_unique<SparseVector<UniqueString>>();
		displayLines = std::make_unique<Partitioning<Sci::Line>>(4);
		InsertLines(0, linesInDocument);
	}
}

void ContractionState::InsertLine(Sci::Line lineDoc) {
	if (OneToOne()) {
		linesInDocument++;
	} else {
		visible->InsertSpace(lineDoc, 1);
		visible->SetValueAt(lineDoc, 1);
		expanded->InsertSpace(lineDoc, 1);
		expanded->SetValueAt(lineDoc, 1);
		heights->InsertSpace(lineDoc, 1);
		heights->SetValueAt(lineDoc, 1);
		foldDisplayTexts->InsertSpace(lineDoc, 1);
		foldDisplayTexts->SetValueAt(lineDoc, nullptr);
		const Sci::Line lineDisplay = DisplayFromDoc(lineDoc);
		displayLines->InsertPartition(lineDoc, lineDisplay);
		displayLines->InsertText(lineDoc, 1);
	}
}

void ContractionState::DeleteLine(Sci::Line lineDoc) {
	if (OneToOne()) {
		linesInDocument--;
	} else {
		if (GetVisible(lineDoc)) {
			displayLines->InsertText(lineDoc, -heights->ValueAt(lineDoc));
		}
		displayLines->RemovePartition(lineDoc);
		visible->DeleteRange(lineDoc, 1);
		expanded->DeleteRange(lineDoc, 1);
		heights->DeleteRange(lineDoc, 1);
		foldDisplayTexts->DeletePosition(lineDoc);
	}
}

void ContractionState::Clear() noexcept {
	visible.reset();
	expanded.reset();
	heights.reset();
	foldDisplayTexts.reset();
	displayLines.reset();
	linesInDocument = 1;
}

Sci::Line ContractionState::LinesInDoc() const {
	if (OneToOne()) {
		return linesInDocument;
	} else {
		return displayLines->Partitions() - 1;
	}
}

Sci::Line ContractionState::LinesDisplayed() const {
	if (OneToOne()) {
		return linesInDocument;
	} else {
		return displayLines->PositionFromPartition(LinesInDoc());
	}
}

Sci::Line ContractionState::DisplayFromDoc(Sci::Line lineDoc) const {
	if (OneToOne()) {
		return (lineDoc <= linesInDocument) ? lineDoc : linesInDocument;
	} else {
		if (lineDoc > displayLines->Partitions())
			lineDoc = displayLines->Partitions();
		return displayLines->PositionFromPartition(lineDoc);
	}
}

Sci::Line ContractionState::DisplayLastFromDoc(Sci::Line lineDoc) const {
	return DisplayFromDoc(lineDoc) + GetHeight(lineDoc) - 1;
}

Sci::Line ContractionState::DocFromDisplay(Sci::Line lineDisplay) const {
	if (OneToOne()) {
		return lineDisplay;
	} else {
		if (lineDisplay <= 0) {
			return 0;
		}
		if (lineDisplay > LinesDisplayed()) {
			return displayLines->PartitionFromPosition(LinesDisplayed());
		}
		const Sci::Line lineDoc = displayLines->PartitionFromPosition(lineDisplay);
		PLATFORM_ASSERT(GetVisible(lineDoc));
		return lineDoc;
	}
}

void ContractionState::InsertLines(Sci::Line lineDoc, Sci::Line lineCount) {
	for (int l = 0; l < lineCount; l++) {
		InsertLine(lineDoc + l);
	}
	Check();
}

void ContractionState::DeleteLines(Sci::Line lineDoc, Sci::Line lineCount) {
	for (Sci::Line l = 0; l < lineCount; l++) {
		DeleteLine(lineDoc);
	}
	Check();
}

bool ContractionState::GetVisible(Sci::Line lineDoc) const {
	if (OneToOne()) {
		return true;
	} else {
		if (lineDoc >= visible->Length())
			return true;
		return visible->ValueAt(lineDoc) == 1;
	}
}

bool ContractionState::SetVisible(Sci::Line lineDocStart, Sci::Line lineDocEnd, bool isVisible) {
	if (OneToOne() && isVisible) {
		return false;
	} else {
		EnsureData();
		Sci::Line delta = 0;
		Check();
		if ((lineDocStart <= lineDocEnd) && (lineDocStart >= 0) && (lineDocEnd < LinesInDoc())) {
			for (Sci::Line line = lineDocStart; line <= lineDocEnd; line++) {
				if (GetVisible(line) != isVisible) {
					const int difference = isVisible ? heights->ValueAt(line) : -heights->ValueAt(line);
					visible->SetValueAt(line, isVisible ? 1 : 0);
					displayLines->InsertText(line, difference);
					delta += difference;
				}
			}
		} else {
			return false;
		}
		Check();
		return delta != 0;
	}
}

bool ContractionState::HiddenLines() const {
	if (OneToOne()) {
		return false;
	} else {
		return !visible->AllSameAs(1);
	}
}

const char *ContractionState::GetFoldDisplayText(Sci::Line lineDoc) const {
	Check();
	return foldDisplayTexts->ValueAt(lineDoc).get();
}

bool ContractionState::GetFoldDisplayTextShown(Sci::Line lineDoc) const {
	return !GetExpanded(lineDoc) && GetFoldDisplayText(lineDoc);
}

bool ContractionState::SetFoldDisplayText(Sci::Line lineDoc, const char *text) {
	EnsureData();
	const char *foldText = foldDisplayTexts->ValueAt(lineDoc).get();
	if (!foldText || !text || 0 != strcmp(text, foldText)) {
		foldDisplayTexts->SetValueAt(lineDoc, UniqueStringCopy(text));
		Check();
		return true;
	} else {
		Check();
		return false;
	}
}

bool ContractionState::GetExpanded(Sci::Line lineDoc) const {
	if (OneToOne()) {
		return true;
	} else {
		Check();
		return expanded->ValueAt(lineDoc) == 1;
	}
}

bool ContractionState::SetExpanded(Sci::Line lineDoc, bool isExpanded) {
	if (OneToOne() && isExpanded) {
		return false;
	} else {
		EnsureData();
		if (isExpanded != (expanded->ValueAt(lineDoc) == 1)) {
			expanded->SetValueAt(lineDoc, isExpanded ? 1 : 0);
			Check();
			return true;
		} else {
			Check();
			return false;
		}
	}
}

Sci::Line ContractionState::ContractedNext(Sci::Line lineDocStart) const {
	if (OneToOne()) {
		return -1;
	} else {
		Check();
		if (!expanded->ValueAt(lineDocStart)) {
			return lineDocStart;
		} else {
			const Sci::Line lineDocNextChange = expanded->EndRun(lineDocStart);
			if (lineDocNextChange < LinesInDoc())
				return lineDocNextChange;
			else
				return -1;
		}
	}
}

int ContractionState::GetHeight(Sci::Line lineDoc) const {
	if (OneToOne()) {
		return 1;
	} else {
		return heights->ValueAt(lineDoc);
	}
}

// Set the number of display lines needed for this line.
// Return true if this is a change.
bool ContractionState::SetHeight(Sci::Line lineDoc, int height) {
	if (OneToOne() && (height == 1)) {
		return false;
	} else if (lineDoc < LinesInDoc()) {
		EnsureData();
		if (GetHeight(lineDoc) != height) {
			if (GetVisible(lineDoc)) {
				displayLines->InsertText(lineDoc, height - GetHeight(lineDoc));
			}
			heights->SetValueAt(lineDoc, height);
			Check();
			return true;
		} else {
			Check();
			return false;
		}
	} else {
		return false;
	}
}

void ContractionState::ShowAll() {
	const Sci::Line lines = LinesInDoc();
	Clear();
	linesInDocument = lines;
}

// Debugging checks

void ContractionState::Check() const {
#ifdef CHECK_CORRECTNESS
	for (Sci::Line vline = 0; vline < LinesDisplayed(); vline++) {
		const Sci::Line lineDoc = DocFromDisplay(vline);
		PLATFORM_ASSERT(GetVisible(lineDoc));
	}
	for (Sci::Line lineDoc = 0; lineDoc < LinesInDoc(); lineDoc++) {
		const Sci::Line displayThis = DisplayFromDoc(lineDoc);
		const Sci::Line displayNext = DisplayFromDoc(lineDoc + 1);
		const Sci::Line height = displayNext - displayThis;
		PLATFORM_ASSERT(height >= 0);
		if (GetVisible(lineDoc)) {
			PLATFORM_ASSERT(GetHeight(lineDoc) == height);
		} else {
			PLATFORM_ASSERT(0 == height);
		}
	}
#endif
}

}

namespace Scintilla {

std::unique_ptr<IContractionState> ContractionStateCreate() {
	return std::make_unique<ContractionState>();
}

}
