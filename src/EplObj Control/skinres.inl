namespace{
constexpr unsigned char defskin[]={46,83,72,69,0,3,100,85,3,0,93,0,0,128,0,0,0,111,248,89,155,204,22,57,235,60,222,20,177,123,123,229,6,159,80,156,214,197,189,113,248,224,210,89,174,239,5,212,148,215,250,23,38,134,131,22,201,7,101,246,42,110,104,60,19,246,218,246,134,190,236,84,100,141,192,180,176,249,46,46,211,45,167,109,95,86,46,233,85,109,10,210,52,36,146,255,160,108,107,167,105,187,141,112,174,161,93,157,118,178,114,6,19,47,209,95,6,50,228,131,159,65,127,12,63,113,160,228,251,141,28,221,15,38,224,187,179,102,255,232,97,165,225,187,40,194,208,47,247,13,26,21,45,15,95,69,8,32,213,227,98,203,86,75,2,246,173,251,240,123,192,221,56,108,174,100,128,72,227,90,158,126,25,189,224,101,249,234,221,197,251,8,65,59,238,128,214,92,167,156,73,69,226,218,155,165,100,74,177,54,84,27,20,208,68,240,132,235,163,203,176,27,61,154,139,65,159,38,53,189,72,57,216,251,24,30,206,91,15,138,33,61,55,109,154,15,135,130,201,108,161,23,109,244,95,93,254,206,175,220,43,202,239,91,145,143,211,55,230,151,249,13,125,237,126,117,140,248,247,4,51,23,146,164,43,94,70,107,145,168,87,141,72,14,46,224,64,187,245,37,37,132,112,124,41,91,145,115,29,137,141,118,149,195,21,163,208,222,101,53,10,56,65,114,222,159,100,105,38,117,200,17,224,122,100,103,202,224,235,133,206,7,85,15,15,75,215,113,70,13,65,83,94,46,37,69,195,9,112,218,126,86,49,232,221,222,92,197,178,246,229,121,140,62,213,134,4,66,38,250,45,204,198,209,235,91,164,103,27,246,169,110,207,50,22,254,65,57,174,195,38,113,162,197,177,27,15,238,227,200,71,166,103,245,128,121,142,167,68,57,188,93,199,122,78,215,170,109,154,142,51,2,0,178,184,25,137,112,186,184,133,106,221,148,145,10,151,120,196,12,169,40,54,161,104,200,57,167,194,194,107,169,231,0,65,164,242,177,146,223,209,177,122,185,181,188,34,72,139,226,248,118,237,136,47,155,187,182,213,145,171,19,50,180,211,76,68,142,112,226,7,141,27,132,121,201,62,23,205,53,12,39,117,85,194,25,44,106,236,28,244,214,138,168,17,187,129,93,75,172,216,230,128,228,91,22,157,53,207,60,20,123,82,75,10,202,125,172,125,227,145,40,28,57,177,157,14,123,206,184,28,250,139,47,81,173,242,120,244,131,86,238,82,109,236,23,76,127,250,3,125,229,100,168,32,250,239,119,42,250,41,140,2,40,168,237,168,7,75,73,71,150,139,211,160,109,224,29,28,145,184,134,255,229,174,162,132,225,85,38,32,38,247,163,20,134,192,53,80,202,5,238,85,40,21,119,138,9,51,104,10,231,137,20,85,52,61,63,51,151,57,194,80,38,204,121,251,187,161,41,68,64,52,26,125,108,12,54,220,237,129,87,107,13,179,174,24,225,198,143,234,242,109,158,239,156,204,36,22,162,117,189,209,239,198,249,35,3,189,186,176,230,13,158,131,21,127,238,196,25,9,107,161,100,152,23,21,111,68,227,213,241,82,200,203,29,210,125,195,89,233,73,246,98,207,49,8,248,86,71,224,174,179,110,116,225,145,246,187,239,229,108,41,189,189,201,198,104,75,99,117,147,164,139,102,42,15,11,77,31,99,133,199,216,131,103,3,246,193,127,168,187,102,125,72,178,69,211,107,23,220,19,158,2,39,26,134,53,218,38,148,190,27,8,75,252,234,150,197,156,198,65,249,153,79,212,159,197,154,45,224,204,21,114,157,105,207,107,157,223,97,223,220,39,129,128,120,163,140,23,174,13,149,139,228,35,159,35,239,242,200,129,188,166,248,193,107,156,241,15,126,65,105,71,166,36,245,241,176,7,203,105,214,185,48,242,100,59,3,81,80,184,78,83,50,13,104,243,121,167,182,130,252,82,225,134,180,112,129,254,157,240,58,66,154,127,218,109,13,228,12,240,150,220,175,183,84,246,252,138,37,117,16,182,144,29,94,68,123,116,212,21,93,227,165,101,113,200,133,15,127,241,180,28,237,223,81,135,64,242,17,80,125,213,206,216,77,250,124,150,56,102,178,9,174,162,36,78,89,76,107,34,31,213,100,34,185,136,17,248,129,196,215,28,195,28,144,6,51,188,117,73,98,244,235,164,49,231,32,127,157,232,176,208,110,78,47,240,174,16,249,180,223,151,72,1,34,10,218,214,150,237,228,184,35,157,12,29,205,85,214,160,19,85,189,44,23,11,19,97,69,108,90,69,217,50,94,228,115,0,131,29,46,124,99,58,192,164,109,162,186,60,239,252,51,110,139,138,62,92,175,160,159,47,25,179,139,211,6,42,134,157,212,254,222,16,25,95,104,172,5,122,139,165,0,143,47,210,221,98,8,52,65,171,199,147,149,8,227,126,129,24,150,95,79,149,118,22,28,238,3,217,60,234,246,156,218,35,107,237,236,52,196,28,128,75,0,45,137,110,52,204,218,245,11,209,200,190,61,113,156,87,194,200,104,82,56,109,72,67,253,42,199,123,162,164,199,131,201,173,140,227,247,191,138,110,180,49,178,123,159,130,13,214,247,78,129,57,156,193,233,128,40,201,205,107,241,88,36,202,214,45,114,44,137,124,95,248,77,37,43,105,6,100,130,27,136,56,4,159,20,102,245,229,103,192,6,247,126,131,97,70,153,0,55,105,251,122,6,29,31,204,210,1,125,57,69,133,226,84,214,95,239,97,37,35,155,175,155,204,255,144,193,217,152,2,197,145,14,105,216,110,249,151,219,127,234,0,83,221,62,161,65,233,193,13,38,99,149,201,80,0,101,115,149,128,236,100,125,76,35,169,123,168,93,97,131,6,206,207,118,243,119,151,102,114,195,180,128,87,119,27,244,70,178,196,217,217,234,54,34,173,36,152,82,187,132,220,254,92,71,251,86,211,97,226,19,103,237,183,155,249,241,184,182,175,255,242,251,223,126,142,65,34,200,156,224,88,189,177,51,161,58,36,27,166,97,125,46,250,234,130,254,74,211,118,219,125,227,233,159,144,201,114,108,9,173,213,113,124,210,58,135,235,183,155,249,46,14,47,58,103,223,68,254,97,128,167,107,49,81,241,201,77,185,243,183,15,122,184,37,195,79,3,243,64,3,64,12,213,32,68,99,65,131,170,82,55,39,47,40,20,47,54,133,24,233,173,176,158,54,149,119,11,60,253,72,85,197,44,242,62,209,157,229,97,176,214,58,78,128,111,164,21,15,126,179,57,25,229,169,70,115,184,136,47,207,37,51,114,108,170,27,185,191,226,128,151,151,17,174,105,201,105,182,46,146,182,153,196,10,213,244,99,96,126,208,90,114,83,17,210,203,72,168,244,97,89,253,141,119,188,43,58,47,52,157,110,17,117,127,207,91,124,188,189,251,107,10,188,29,250,87,4,75,226,84,166,254,188,245,230,209,41,241,14,176,74,29,131,234,109,134,24,87,114,179,25,81,161,37,152,182,30,145,77,73,5,98,57,35,64,177,22,138,57,164,233,145,73,115,123,194,152,154,193,143,131,13,247,54,155,174,63,189,215,116,246,49,26,65,255,85,26,86,15,7,185,107,250,31,43,177,196,177,179,92,170,156,62,232,115,113,162,222,164,132,128,176,55,203,234,184,135,84,80,207,166,111,64,19,152,243,74,129,77,199,136,218,190,95,173,42,245,166,198,27,87,206,122,126,142,227,112,223,157,50,49,142,110,163,39,152,161,208,132,253,55,88,16,176,137,43,203,124,38,111,250,242,210,63,209,131,55,243,15,224,27,23,84,187,159,164,177,19,25,161,101,21,83,5,179,75,201,203,127,42,201,146,22,202,89,221,181,199,26,119,226,42,184,226,64,13,73,83,210,207,51,172,210,167,212,213,77,191,99,167,153,33,6,24,155,54,90,202,241,210,9,192,34,121,132,143,23,23,158,191,62,250,96,152,23,242,170,32,172,194,32,179,195,213,230,70,134,173,134,68,203,165,2,6,69,20,12,158,66,1,248,106,251,179,78,0,68,207,234,186,149,182,183,54,212,80,132,139,236,62,195,110,74,54,24,201,173,251,80,173,135,191,7,127,15,87,242,6,237,41,83,104,160,33,119,68,246,117,4,38,82,90,35,105,132,124,118,140,175,230,44,71,169,164,199,73,235,226,245,37,92,8,129,61,143,249,164,220,81,220,145,108,14,35,238,229,119,245,221,148,220,90,52,220,0,161,94,43,212,4,54,119,229,186,131,161,100,15,190,67,3,204,194,190,93,251,212,195,166,170,181,137,214,94,232,141,115,148,134,43,229,102,182,16,200,15,4,187,45,87,87,92,153,252,177,54,15,182,71,167,68,238,48,145,214,28,220,170,122,90,37,82,22,52,174,46,65,236,197,94,180,161,158,159,56,180,32,129,207,202,108,6,104,202,16,227,178,51,116,202,230,81,217,217,225,134,122,8,223,221,9,141,93,169,121,228,169,60,207,183,155,114,66,104,90,1,25,28,254,66,71,180,217,36,7,202,162,10,22,122,121,162,29,71,168,181,67,60,163,184,247,175,121,156,32,95,43,146,110,224,129,241,156,198,177,56,202,248,85,119,132,50,200,193,143,144,248,108,220,40,126,255,118,69,103,44,87,209,218,172,186,6,75,47,177,37,143,84,211,83,133,34,151,208,181,84,241,84,29,254,226,89,3,56,95,226,203,102,85,216,119,222,148,74,9,194,173,129,30,164,67,59,161,176,239,198,172,213,148,25,130,161,125,240,112,154,188,206,243,47,190,6,8,248,107,130,156,155,98,22,247,56,91,157,198,101,175,122,37,37,234,59,55,82,212,65,80,213,45,250,196,205,56,233,133,255,88,53,27,47,36,51,68,119,141,142,234,193,117,12,11,104,170,200,253,25,50,153,230,225,229,48,117,254,113,98,248,203,63,193,151,88,214,238,198,237,26,95,196,108,50,137,78,249,118,17,99,73,25,169,114,198,210,150,17,222,117,141,160,138,225,234,244,166,164,197,154,77,62,232,150,113,125,155,13,181,166,42,213,104,203,232,209,213,96,245,117,126,164,238,173,180,56,189,193,134,226,138,96,123,169,245,219,133,145,64,138,52,170,110,34,66,249,68,176,217,134,147,21,166,210,46,209,159,68,81,123,173,89,174,2,142,112,74,85,98,28,18,89,175,252,249,155,176,43,139,173,19,178,113,190,187,114,158,9,208,208,110,138,10,75,160,7,240,107,96,179,133,153,193,142,232,4,93,209,148,152,124,144,93,253,43,129,125,18,197,108,178,250,57,148,129,175,112,239,214,198,33,6,128,189,194,142,60,197,156,42,57,70,192,214,66,35,23,81,101,32,234,35,208,64,220,138,115,123,168,138,57,211,48,203,14,119,218,229,231,47,243,125,142,133,8,192,128,118,160,80,9,238,83,160,111,106,45,232,102,208,83,115,204,203,53,158,197,86,186,105,160,118,246,52,53,207,74,180,230,186,206,90,28,83,74,45,219,206,254,165,188,90,117,234,22,18,220,135,3,156,0,202,60,128,157,183,133,183,233,138,174,122,44,6,105,7,21,208,213,236,232,78,234,35,198,71,231,189,70,252,5,199,134,244,38,160,124,21,183,123,130,149,140,37,29,40,161,114,221,48,152,122,195,106,216,209,0,107,4,150,222,56,0,4,118,16,67,50,36,115,164,2,99,106,100,47,231,175,59,241,13,5,63,152,104,191,153,79,181,77,86,79,253,184,203,96,71,190,187,117,127,61,82,75,79,195,140,226,48,217,14,187,214,9,62,123,64,63,72,169,196,236,125,116,169,37,81,32,82,128,184,39,12,21,80,142,155,148,14,85,94,58,149,54,249,243,213,61,173,146,37,119,107,71,121,142,118,107,46,235,207,230,138,54,251,128,113,92,57,211,12,16,62,192,195,107,25,96,157,184,21,217,25,234,109,75,68,217,91,211,56,163,64,252,173,116,215,239,11,199,71,100,4,137,54,174,101,243,132,29,125,118,71,144,88,198,49,228,109,198,70,146,147,69,30,24,235,208,83,76,207,238,35,210,188,97,88,19,218,21,220,196,112,71,239,0,126,66,239,129,240,156,29,173,59,111,167,33,102,190,76,180,124,53,196,97,54,151,178,28,95,70,154,120,95,0,123,77,82,169,45,16,216,96,81,132,132,164,161,162,158,123,26,105,241,92,192,208,131,224,191,37,39,225,93,142,23,240,39,43,66,59,165,18,72,145,202,64,220,218,23,127,85,119,77,91,44,230,226,135,69,131,17,85,62,41,249,10,9,172,158,254,98,46,225,108,254,56,157,120,178,19,0,209,187,186,207,37,81,226,111,116,219,86,136,213,203,184,234,12,236,245,1,236,93,131,118,14,160,119,142,24,246,212,70,2,152,50,190,252,180,220,134,184,33,197,70,24,7,171,95,63,238,248,94,91,230,245,57,182,180,65,112,70,234,42,246,47,115,74,233,224,138,212,30,222,46,170,176,122,44,222,196,207,79,34,97,46,59,51,82,1,223,109,85,37,56,37,179,67,150,193,151,119,199,162,4,167,146,88,65,83,135,148,167,3,54,50,130,76,235,199,101,11,99,57,205,32,165,111,242,233,99,13,133,95,186,135,236,90,216,70,114,92,111,43,152,57,179,66,117,239,15,223,175,162,153,133,45,161,49,138,125,106,98,216,15,183,156,226,54,70,245,210,28,231,39,49,32,180,141,151,243,230,213,163,127,115,195,226,149,109,60,228,172,53,245,87,239,196,6,213,54,156,125,44,107,79,253,81,143,80,218,97,30,169,184,128,79,190,30,180,79,233,5,193,99,32,42,98,48,5,28,169,92,136,22,38,68,196,73,163,81,222,52,1,92,93,145,71,199,160,164,197,227,66,133,161,75,172,53,58,29,216,42,137,49,114,110,5,227,192,236,101,234,65,148,215,225,161,178,160,4,106,235,11,4,166,71,112,95,233,167,50,31,78,75,180,170,84,12,32,115,178,131,177,137,212,64,160,143,238,52,195,177,210,36,76,185,83,183,20,74,88,177,39,31,106,120,80,59,204,72,114,230,41,10,128,160,132,88,233,42,251,163,201,216,29,184,124,186,113,246,209,127,8,37,215,11,187,218,35,186,5,209,176,246,47,61,32,135,40,13,177,75,21,42,177,237,206,195,183,179,191,165,46,87,233,228,244,125,208,182,59,237,252,219,251,234,54,23,49,158,77,164,212,185,138,80,121,7,72,21,248,221,140,118,102,164,189,36,131,85,184,49,30,184,151,188,235,81,177,57,47,250,210,59,9,247,231,222,110,30,146,95,61,111,49,1,183,2,179,64,158,158,142,207,233,33,165,159,188,194,35,167,173,183,219,110,35,131,191,33,108,218,223,234,22,41,117,115,235,196,144,170,22,148,173,208,106,219,59,7,176,92,17,116,26,138,41,31,136,116,98,104,61,47,98,157,183,10,6,105,225,132,125,229,155,249,29,63,30,2,88,69,121,152,225,236,176,124,195,153,1,247,239,202,24,182,124,130,104,132,192,193,45,40,135,58,182,21,61,117,235,221,28,68,173,73,163,142,161,188,49,58,199,251,132,19,50,96,132,49,42,213,40,232,247,129,40,192,190,253,236,19,36,147,64,103,202,159,155,70,92,25,114,246,65,2,28,198,221,22,88,89,230,235,187,25,202,122,28,35,150,224,144,74,175,51,78,20,179,230,183,106,251,32,254,95,193,157,26,206,166,235,190,195,131,221,27,165,105,30,236,33,213,88,94,139,175,182,136,29,116,157,41,81,158,57,205,70,216,223,99,124,115,21,33,184,69,110,100,201,4,18,140,142,29,91,143,16,129,255,249,40,134,154,77,46,51,240,236,243,151,170,239,74,62,243,120,62,186,12,32,46,138,48,124,102,15,143,41,81,98,58,170,224,204,73,65,223,20,154,107,225,123,210,48,96,184,37,150,52,88,224,232,222,0};

constexpr auto skinsize=std::size(defskin);
};