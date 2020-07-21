#ifndef _FB2FILE_TEMPLATE_H
#define _FB2FILE_TEMPLATE_H

#include <string>
#include "../../DesktopEditor/common/File.h"
#include "../../OfficeUtils/src/OfficeUtils.h"

static bool ExtractTemplate(const std::wstring& sDirectory)
{
    // [START]
    int template_binary_len = 6369;
    BYTE template_binary[6369] = {80,75,3,4,20,0,0,0,0,0,82,137,238,80,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,119,111,114,100,47,80,75,3,4,20,0,0,0,8,0,45,109,238,80,250,111,5,35,60,1,0,0,241,2,0,0,18,0,0,0,119,111,114,100,47,102,111,110,116,84,97,98,108,101,46,120,109,108,149,208,205,110,194,48,12,0,224,87,137,114,31,13,165,160,169,162,160,253,8,105,151,29,38,246,0,33,164,16,45,177,171,56,208,241,246,243,186,194,14,140,141,41,138,226,40,241,39,219,211,249,123,240,98,111,35,57,132,74,14,7,74,10,11,6,215,14,54,149,124,93,46,110,110,165,160,164,97,173,61,130,173,228,193,146,156,207,166,109,89,35,36,18,156,13,84,6,83,201,109,74,77,153,101,100,182,54,104,26,96,99,129,31,107,140,65,39,190,198,77,22,116,124,219,53,55,6,67,163,147,91,57,239,210,33,203,149,154,200,158,137,215,40,88,215,206,216,71,52,187,96,33,117,249,89,180,158,69,4,218,186,134,142,90,123,141,214,98,92,55,17,141,37,226,142,131,239,60,174,212,193,137,25,22,103,80,112,38,34,97,157,6,220,76,95,81,71,113,250,80,117,81,240,223,192,248,127,64,126,2,130,41,159,54,128,81,175,60,143,158,43,17,140,201,227,244,69,91,130,14,252,176,116,193,146,120,182,173,120,193,160,161,251,208,104,64,178,67,254,179,215,190,146,42,231,53,81,35,53,86,5,239,156,163,66,102,179,105,246,69,157,145,119,209,105,127,1,186,103,168,224,179,95,191,67,15,218,187,85,116,23,168,133,26,31,17,53,250,155,10,44,233,159,169,207,182,250,246,38,103,212,41,160,217,7,80,75,3,4,20,0,0,0,8,0,50,109,238,80,40,106,10,222,151,2,0,0,107,6,0,0,17,0,0,0,119,111,114,100,47,115,101,116,116,105,110,103,115,46,120,109,108,181,85,97,79,219,48,16,253,43,149,63,175,164,116,208,161,142,128,24,168,218,166,193,16,129,31,224,198,215,198,194,246,69,246,165,165,252,250,157,155,184,41,171,132,38,161,125,106,239,221,187,187,103,251,94,123,126,249,98,205,96,5,62,104,116,185,56,62,26,137,1,184,18,149,118,203,92,60,61,206,134,103,98,16,72,58,37,13,58,200,197,6,130,184,188,56,95,79,3,16,49,41,12,184,129,11,211,117,46,42,162,122,154,101,161,172,192,202,112,132,53,56,206,45,208,91,73,28,250,101,182,70,175,106,143,37,132,192,165,214,100,227,209,104,146,89,169,157,232,218,216,127,105,131,139,133,46,225,6,203,198,130,163,212,132,170,212,4,115,209,120,55,237,58,12,173,46,61,6,92,208,176,68,59,109,139,187,143,84,177,122,175,98,101,141,136,39,46,141,47,34,1,110,101,93,179,254,193,122,42,203,146,21,28,231,162,251,34,118,216,56,97,227,30,251,156,176,207,61,118,146,176,147,30,59,77,216,105,143,77,18,54,137,216,124,201,51,141,94,86,60,114,27,142,219,176,157,182,64,99,112,13,234,251,166,6,111,180,123,206,197,1,20,121,85,159,175,246,241,120,32,37,253,243,241,54,24,183,193,88,100,241,18,20,44,100,99,232,81,206,11,194,154,243,43,105,114,241,101,116,22,211,118,26,159,225,222,111,153,228,101,249,252,0,43,29,87,43,36,230,66,154,0,145,27,101,34,57,36,184,247,251,17,19,181,202,197,240,152,73,135,240,168,69,93,99,103,150,82,79,5,165,182,210,236,82,15,192,27,235,119,233,18,29,111,106,131,77,216,49,138,253,124,55,169,198,157,200,90,46,225,27,18,161,141,169,236,111,169,221,188,98,99,231,104,82,205,167,182,139,209,129,10,168,165,151,132,62,229,190,182,57,94,166,90,82,255,173,104,45,196,44,39,45,123,171,69,245,92,27,77,155,91,84,16,239,191,241,250,192,19,187,253,60,226,146,206,14,91,115,137,221,153,78,250,145,135,131,144,13,239,181,2,126,69,3,5,109,12,204,248,142,10,253,10,87,78,253,108,2,105,238,200,74,208,125,64,193,123,2,192,197,201,191,217,218,143,188,120,51,144,212,120,8,255,105,152,194,59,164,153,209,245,173,246,30,253,15,167,216,70,31,29,150,237,63,231,43,162,229,44,91,40,58,148,25,163,81,39,168,146,236,2,2,95,212,178,100,77,215,124,205,62,237,76,167,236,154,219,240,225,187,229,36,86,177,125,141,95,210,45,19,15,220,240,169,136,243,65,6,186,10,90,230,226,181,26,94,223,181,37,161,146,53,220,180,190,12,23,231,216,2,170,3,6,171,41,188,16,247,80,154,248,167,188,214,202,202,151,40,113,60,225,242,196,54,114,131,13,189,225,198,92,36,215,111,59,40,73,50,221,193,155,98,142,15,180,100,253,255,196,197,31,80,75,3,4,20,0,0,0,8,0,89,100,239,80,87,138,75,117,93,7,0,0,245,51,0,0,15,0,0,0,119,111,114,100,47,115,116,121,108,101,115,46,120,109,108,205,154,73,143,211,48,20,199,191,74,148,123,105,218,164,27,162,32,118,144,216,215,35,74,19,119,106,72,147,16,59,108,55,56,112,225,128,196,133,35,18,159,0,177,8,4,130,207,208,249,70,60,59,139,219,44,77,156,148,14,51,234,76,227,196,207,126,191,255,243,75,94,146,19,167,158,45,29,229,9,10,8,246,220,169,218,59,166,169,10,114,45,207,198,238,193,84,189,123,231,66,103,172,42,132,154,174,109,58,158,139,166,234,115,68,212,83,39,79,60,61,78,232,115,7,17,5,186,187,228,248,210,154,170,11,74,253,227,221,46,177,22,104,105,146,99,158,143,92,216,57,247,130,165,73,97,51,56,232,46,205,224,81,232,119,44,111,233,155,20,207,176,131,233,243,110,95,211,134,106,108,38,168,99,197,155,207,177,133,206,121,86,184,68,46,229,253,187,1,114,192,162,231,146,5,246,73,98,237,105,29,107,79,189,192,246,3,207,66,132,128,203,75,135,219,131,153,98,55,53,211,51,114,134,150,216,10,60,226,205,233,49,112,38,158,17,55,5,221,123,26,255,182,116,132,129,129,156,129,126,106,96,105,29,191,124,224,122,129,57,115,128,61,204,68,1,99,42,195,111,123,214,57,52,55,67,135,18,182,25,220,8,226,205,120,139,255,187,224,185,148,40,79,143,155,196,194,120,170,158,14,176,233,168,176,189,56,237,146,245,109,139,172,109,32,147,208,211,4,155,235,199,99,151,78,85,59,26,64,237,114,249,95,64,251,19,211,153,170,253,126,210,114,150,100,219,28,211,61,72,218,130,176,115,235,46,179,54,195,54,12,110,6,157,219,167,55,199,67,110,231,238,109,214,177,27,187,208,205,58,230,103,183,248,192,190,105,97,62,142,131,93,116,43,100,168,204,144,122,106,220,2,211,25,13,217,134,57,167,8,66,12,20,142,7,241,249,32,155,102,187,27,108,211,72,135,238,244,185,15,182,124,51,48,15,2,211,95,128,197,104,215,101,123,170,206,76,130,88,67,204,8,86,18,87,201,53,151,40,241,255,26,139,58,39,226,242,248,2,15,65,54,139,216,72,221,129,40,166,14,202,27,191,132,76,155,49,232,69,246,217,116,236,235,110,178,151,109,178,29,156,199,163,168,53,49,213,177,50,83,18,241,51,139,108,157,37,252,191,229,57,94,144,244,213,248,143,202,38,11,1,141,206,178,125,96,17,61,163,189,108,124,24,99,17,31,162,77,200,188,166,228,35,132,252,43,160,24,12,24,111,93,3,139,221,53,145,133,138,124,240,25,130,181,140,152,61,45,26,196,11,41,147,252,202,19,39,25,106,77,235,134,180,251,165,180,251,178,180,251,69,180,67,119,129,109,116,127,129,220,187,96,231,31,8,160,237,22,118,95,43,133,221,107,13,91,47,133,173,203,194,214,219,192,198,209,223,150,232,245,161,136,125,209,182,55,57,250,173,229,48,74,229,48,100,229,48,228,228,216,64,222,215,217,111,142,238,218,153,71,180,237,141,174,222,154,238,160,148,238,64,150,238,64,142,238,150,204,98,240,159,220,89,126,92,112,150,223,113,22,223,194,218,104,205,122,88,202,122,40,203,122,40,199,90,164,146,154,113,125,196,172,7,173,89,143,74,89,143,100,89,143,228,88,111,137,235,161,198,126,115,172,141,2,214,198,222,88,15,91,179,30,151,178,30,203,178,30,203,177,174,147,53,142,150,238,168,53,221,73,41,221,137,44,221,137,28,221,56,107,72,100,104,189,128,181,190,55,214,227,122,172,173,5,192,182,192,114,174,124,234,248,21,5,84,92,147,41,55,18,185,20,86,223,70,243,9,241,141,0,123,1,220,80,72,142,78,174,197,208,18,95,194,182,141,220,34,222,242,51,77,138,38,94,54,135,132,122,203,219,108,87,209,124,87,239,87,159,86,95,86,127,86,191,224,243,25,62,63,149,158,2,141,191,161,249,103,89,57,86,230,14,132,219,206,43,251,92,157,32,2,40,95,59,52,145,53,170,121,154,194,234,87,193,234,31,33,44,221,104,13,70,111,10,70,175,2,163,31,37,152,130,40,210,219,71,145,209,20,150,81,5,203,216,59,172,244,34,37,155,193,215,170,69,209,214,26,221,160,41,186,65,21,186,193,255,131,174,242,66,163,17,186,97,83,116,195,42,116,195,255,7,93,225,253,219,214,232,70,77,209,141,170,208,141,142,24,29,142,254,238,11,228,184,41,200,113,21,200,241,222,65,238,25,221,164,41,186,73,21,186,201,255,131,174,87,128,174,215,26,93,83,114,21,220,74,175,214,181,148,155,236,211,3,89,247,8,178,216,163,194,14,9,103,18,158,126,0,239,190,174,190,75,248,187,54,206,118,215,123,169,235,255,250,156,102,97,10,101,86,61,135,223,29,190,1,135,191,173,126,193,231,55,243,241,240,173,114,248,122,245,227,240,21,124,133,79,169,231,201,48,101,254,234,155,82,227,90,254,164,37,250,86,41,115,94,220,142,119,72,212,234,89,155,153,170,189,85,137,62,40,72,115,131,226,27,214,110,184,140,7,113,178,143,87,248,206,218,143,62,141,127,243,100,44,210,56,7,252,178,75,145,75,144,114,51,244,168,12,245,200,92,134,117,189,0,170,253,220,198,24,178,223,172,38,189,137,208,68,180,21,106,130,93,155,113,69,115,10,178,13,71,140,71,128,15,22,209,86,100,229,161,149,250,233,209,69,108,121,97,167,110,58,200,132,37,25,79,76,104,53,199,14,236,61,207,127,162,78,254,25,27,198,140,70,75,67,19,164,118,208,90,247,177,198,126,185,46,47,192,63,248,194,35,2,68,139,67,143,122,126,131,206,60,204,34,223,90,140,13,0,32,193,52,232,31,69,121,132,160,121,128,22,39,132,59,146,217,128,91,249,231,143,200,71,5,121,97,148,207,11,209,16,46,51,17,154,206,237,104,237,167,51,13,66,152,127,253,164,32,238,240,141,55,110,241,233,154,38,34,176,134,142,220,203,84,199,254,186,144,37,206,11,117,91,229,165,173,103,247,154,103,185,244,232,7,169,181,242,51,130,175,54,120,95,35,237,44,51,27,137,0,77,251,100,131,52,151,183,230,56,32,244,10,215,127,164,77,138,210,85,27,238,166,235,122,148,191,131,85,11,188,56,124,27,121,113,212,206,46,25,132,73,169,89,74,40,34,58,109,187,116,168,58,191,104,201,217,133,127,223,148,207,232,15,118,45,223,147,14,123,201,239,133,89,75,188,228,224,114,233,196,49,59,19,46,49,40,49,63,9,209,146,46,255,74,50,88,113,50,201,185,133,146,200,199,28,94,205,12,40,14,223,166,166,56,106,103,122,38,38,107,101,198,228,96,169,212,40,58,181,81,85,159,12,39,91,132,213,178,43,145,31,183,39,173,231,158,71,33,217,100,47,115,196,14,37,64,115,20,192,11,189,165,213,231,100,162,86,60,136,132,151,131,233,105,7,31,164,180,73,232,195,251,194,86,128,125,90,175,24,77,3,160,112,242,29,191,124,250,236,130,161,76,113,232,152,211,92,24,181,202,29,174,247,96,176,160,32,239,173,221,119,144,123,255,116,227,122,107,55,154,215,90,221,171,143,80,189,255,60,124,121,248,74,57,124,9,229,250,31,248,251,115,245,99,75,237,46,84,217,2,176,14,158,114,191,40,123,155,57,243,172,87,120,24,239,239,112,193,75,94,162,85,238,192,33,149,33,93,173,48,157,57,55,130,248,203,101,190,230,159,178,21,157,206,212,126,102,170,201,129,103,145,227,92,53,131,184,170,42,59,52,202,26,209,222,158,54,206,237,23,151,211,249,254,162,234,218,98,160,187,62,153,100,179,38,239,77,194,249,218,136,181,42,23,3,108,23,44,185,13,89,202,200,15,24,121,177,48,242,239,18,108,46,137,220,138,17,235,34,171,206,25,120,33,30,146,78,73,77,155,175,33,181,92,133,34,212,105,222,59,210,174,121,127,166,109,139,225,177,75,32,130,47,181,53,112,175,169,129,238,186,20,245,98,175,56,245,243,34,22,110,140,231,66,144,122,86,229,43,236,5,55,132,10,207,97,91,35,113,80,243,213,160,52,7,23,206,191,224,212,117,9,186,5,44,161,170,141,79,184,155,119,17,6,67,253,108,47,91,72,47,50,163,108,42,90,148,134,197,55,114,242,47,80,75,3,4,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,119,111,114,100,47,116,104,101,109,101,47,80,75,3,4,20,0,0,0,8,0,38,109,238,80,107,155,19,119,133,3,0,0,167,17,0,0,21,0,0,0,119,111,114,100,47,116,104,101,109,101,47,116,104,101,109,101,49,46,120,109,108,237,88,93,111,218,48,20,253,43,145,223,87,231,19,74,85,90,181,80,180,135,77,147,214,78,123,118,19,135,164,117,156,200,54,165,252,251,93,39,1,135,4,74,216,162,105,15,3,137,216,215,62,247,28,95,219,215,14,215,183,239,25,179,222,168,144,105,206,167,200,185,176,145,69,121,152,71,41,95,78,209,143,167,197,167,75,100,73,69,120,68,88,206,233,20,109,168,68,183,55,215,228,74,37,52,163,22,160,185,188,34,83,148,40,85,92,97,44,67,48,19,121,145,23,148,67,91,156,139,140,40,168,138,37,142,4,89,131,215,140,97,215,182,71,56,35,41,71,53,94,244,193,231,113,156,134,116,158,135,171,140,114,85,57,17,148,17,5,202,101,146,22,114,235,173,232,227,173,16,84,130,155,18,189,47,137,147,12,198,249,173,100,179,158,244,40,209,110,188,15,140,106,114,169,13,33,19,143,161,54,54,17,85,223,232,213,209,15,185,145,51,38,172,55,194,166,8,134,30,229,235,39,250,174,144,197,136,84,208,48,69,118,249,1,8,222,118,134,226,14,206,212,17,47,13,15,139,242,211,242,80,67,181,35,183,244,32,150,207,59,23,190,31,248,163,59,141,168,26,12,169,91,145,118,33,15,227,135,209,195,168,13,217,245,37,97,8,49,113,58,176,224,126,114,63,15,58,48,211,191,46,30,98,156,143,231,158,115,4,218,100,245,58,208,187,64,127,143,65,61,3,245,59,208,197,98,182,155,142,46,212,55,208,224,64,84,199,238,204,63,6,13,12,116,212,129,142,237,187,185,63,110,67,247,250,39,44,229,175,29,160,29,140,188,89,55,72,166,119,156,179,207,7,145,147,192,95,140,221,46,210,0,112,99,125,87,174,184,58,176,218,173,25,172,68,153,134,150,91,174,251,140,188,228,98,1,93,117,69,239,76,110,169,77,65,99,18,2,226,78,164,132,105,206,186,73,247,161,228,80,7,109,47,119,152,60,212,170,237,240,104,177,101,41,255,155,212,134,13,215,193,49,161,202,212,177,188,16,167,140,61,170,13,163,95,100,169,83,230,44,141,22,96,44,43,37,104,55,71,69,2,197,146,212,180,64,173,5,90,10,98,202,18,220,86,5,171,200,37,44,16,116,204,111,217,0,129,80,245,78,221,166,161,202,88,162,136,250,154,71,85,179,183,75,83,91,123,71,150,38,109,82,123,224,178,55,189,55,30,154,222,177,237,51,248,157,224,99,254,160,39,63,110,204,1,131,5,72,244,25,234,140,220,74,140,37,67,194,104,4,22,237,170,236,1,207,114,10,7,153,78,153,144,136,214,243,233,212,130,107,107,123,68,142,215,115,68,134,252,242,116,64,27,2,38,222,224,2,250,76,105,83,129,127,74,65,208,79,65,207,73,181,143,77,42,238,110,123,198,247,107,214,122,138,70,94,0,222,66,2,151,151,24,114,20,20,179,2,220,74,190,68,22,97,75,184,155,133,74,160,190,73,99,63,20,193,137,80,216,61,66,177,99,173,134,201,141,114,199,29,219,3,74,63,135,121,98,15,25,180,30,204,184,61,121,52,142,105,168,142,88,76,181,110,203,87,138,138,199,36,90,91,207,108,37,190,19,208,234,87,203,40,74,165,154,34,119,91,17,176,135,161,165,172,137,92,253,76,85,242,152,144,130,234,117,214,189,7,152,157,65,88,145,144,58,107,93,106,35,110,159,241,70,3,212,246,228,225,61,237,127,60,20,111,192,161,4,255,135,178,213,142,15,173,185,231,229,226,31,189,89,248,246,48,71,171,161,246,79,31,3,13,250,253,147,189,157,24,39,251,137,113,0,117,103,158,82,174,253,177,2,55,232,145,154,219,167,84,65,84,98,233,31,72,127,169,8,25,213,248,202,60,232,133,195,132,249,114,240,251,227,153,113,244,78,197,177,175,130,223,139,35,238,110,65,220,120,17,208,181,238,255,7,249,243,11,108,227,57,188,99,172,152,182,224,182,201,192,110,126,1,80,75,3,4,20,0,0,0,8,0,61,109,238,80,122,219,27,192,146,0,0,0,183,0,0,0,20,0,0,0,119,111,114,100,47,119,101,98,83,101,116,116,105,110,103,115,46,120,109,108,85,141,73,14,194,48,12,69,175,18,121,79,83,88,32,84,117,144,88,244,2,192,1,66,107,218,72,141,29,217,17,1,78,79,196,142,229,159,222,111,135,87,216,204,19,69,61,83,7,251,170,6,131,52,241,236,105,233,224,118,29,119,39,48,154,28,205,110,99,194,14,222,168,48,244,166,205,77,198,251,5,83,42,69,53,5,66,218,228,14,214,148,98,99,173,78,43,6,167,21,71,164,146,61,88,130,75,69,202,98,51,203,28,133,39,84,45,211,176,217,67,93,31,109,112,158,224,135,229,152,124,240,31,28,89,206,194,89,81,108,241,237,223,95,255,5,80,75,3,4,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,119,111,114,100,47,95,114,101,108,115,47,80,75,3,4,20,0,0,0,8,0,32,109,238,80,233,249,193,147,123,0,0,0,155,0,0,0,29,0,0,0,119,111,114,100,47,95,114,101,108,115,47,102,111,111,116,110,111,116,101,115,46,120,109,108,46,114,101,108,115,85,204,49,14,2,33,16,133,225,171,144,233,93,86,11,99,204,194,118,30,192,232,1,38,236,8,68,24,8,67,140,222,94,74,45,95,94,254,111,89,223,57,169,23,53,137,133,13,236,167,25,20,177,43,91,100,111,224,126,187,236,78,160,164,35,111,152,10,147,129,15,9,172,118,185,82,194,62,18,9,177,138,26,6,139,129,208,123,61,107,45,46,80,70,153,74,37,30,207,163,180,140,125,204,230,117,69,247,68,79,250,48,207,71,221,126,13,176,139,254,67,237,23,80,75,3,4,20,0,0,0,8,0,14,109,238,80,32,16,105,98,121,1,0,0,100,6,0,0,19,0,0,0,91,67,111,110,116,101,110,116,95,84,121,112,101,115,93,46,120,109,108,181,149,203,110,194,48,16,69,127,37,242,182,74,76,187,168,170,138,192,162,143,101,65,42,253,0,199,153,4,83,191,100,15,175,191,239,36,144,86,66,32,160,192,38,82,236,185,231,222,241,56,74,127,184,50,58,89,64,136,202,217,156,221,103,61,150,128,149,174,84,182,206,217,215,228,61,125,98,73,68,97,75,161,157,133,156,173,33,178,225,160,63,89,123,136,9,105,109,204,217,20,209,63,115,30,229,20,140,136,153,243,96,105,167,114,193,8,164,215,80,115,47,228,183,168,129,63,244,122,143,92,58,139,96,49,197,134,193,6,253,87,168,196,92,99,242,182,162,229,77,142,153,175,89,242,178,169,35,43,242,85,166,209,207,60,212,140,239,149,120,187,95,66,235,7,20,4,59,219,37,128,142,59,26,225,189,86,82,32,237,243,133,45,119,218,79,183,173,103,164,108,107,226,84,249,120,71,5,7,28,10,101,207,51,112,85,165,36,148,78,206,13,73,50,167,97,84,204,64,98,195,31,209,100,131,42,33,25,139,128,31,194,16,141,83,229,56,56,31,57,113,51,226,92,228,6,77,240,18,202,212,7,42,12,168,160,237,237,144,247,210,133,146,35,93,19,216,60,239,47,14,208,98,142,90,86,142,232,162,208,112,177,95,131,163,94,37,196,72,159,136,209,89,135,62,30,98,9,197,39,32,146,44,94,63,198,31,188,29,192,209,225,75,23,254,113,24,221,101,110,212,231,140,60,222,172,239,120,66,211,219,43,224,208,58,132,27,100,216,162,79,57,7,92,235,91,36,104,184,39,216,119,128,235,7,248,221,49,66,217,46,7,111,255,18,131,31,80,75,3,4,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,95,114,101,108,115,47,80,75,3,4,20,0,0,0,8,0,23,109,238,80,42,73,130,205,226,0,0,0,76,2,0,0,11,0,0,0,95,114,101,108,115,47,46,114,101,108,115,141,146,219,74,3,65,12,64,127,101,200,123,119,182,21,68,164,211,190,136,208,55,145,250,1,97,38,123,193,157,11,73,212,246,239,29,68,209,74,173,251,56,153,228,228,36,100,189,61,196,201,188,18,203,152,147,131,101,211,130,161,228,115,24,83,239,224,105,127,191,184,1,35,138,41,224,148,19,57,56,146,192,118,179,126,164,9,181,150,200,48,22,49,149,145,196,193,160,90,110,173,21,63,80,68,105,114,161,84,127,186,204,17,181,62,185,183,5,253,51,246,100,87,109,123,109,249,39,3,78,153,102,23,28,240,46,44,193,236,143,133,230,176,115,215,141,158,238,178,127,137,148,244,76,139,95,25,149,140,220,147,58,120,203,28,108,248,12,55,21,11,246,188,205,106,190,205,223,147,218,72,138,1,21,173,207,76,139,194,181,154,117,36,249,22,170,46,15,53,44,31,25,151,132,174,230,11,253,191,30,58,40,165,64,225,178,18,150,242,101,100,79,174,96,243,14,80,75,1,2,63,0,20,0,0,0,0,0,82,137,238,80,0,0,0,0,0,0,0,0,0,0,0,0,5,0,36,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,119,111,114,100,47,10,0,32,0,0,0,0,0,1,0,24,0,223,76,86,139,232,89,214,1,149,31,194,211,133,90,214,1,224,14,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,45,109,238,80,250,111,5,35,60,1,0,0,241,2,0,0,18,0,36,0,0,0,0,0,0,0,32,0,0,0,35,0,0,0,119,111,114,100,47,102,111,110,116,84,97,98,108,101,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,202,119,23,82,203,89,214,1,211,172,204,211,133,90,214,1,241,53,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,50,109,238,80,40,106,10,222,151,2,0,0,107,6,0,0,17,0,36,0,0,0,0,0,0,0,32,0,0,0,143,1,0,0,119,111,114,100,47,115,101,116,116,105,110,103,115,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,237,210,167,88,203,89,214,1,227,211,204,211,133,90,214,1,241,53,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,89,100,239,80,87,138,75,117,93,7,0,0,245,51,0,0,15,0,36,0,0,0,0,0,0,0,32,0,0,0,85,4,0,0,119,111,114,100,47,115,116,121,108,101,115,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,156,99,214,46,139,90,214,1,156,99,214,46,139,90,214,1,20,171,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,11,0,36,0,0,0,0,0,0,0,16,0,0,0,223,11,0,0,119,111,114,100,47,116,104,101,109,101,47,10,0,32,0,0,0,0,0,1,0,24,0,33,210,89,80,51,88,214,1,75,161,207,73,235,89,214,1,20,171,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,38,109,238,80,107,155,19,119,133,3,0,0,167,17,0,0,21,0,36,0,0,0,0,0,0,0,32,0,0,0,8,12,0,0,119,111,114,100,47,116,104,101,109,101,47,116,104,101,109,101,49,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,61,255,88,74,203,89,214,1,178,102,29,133,232,89,214,1,33,210,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,61,109,238,80,122,219,27,192,146,0,0,0,183,0,0,0,20,0,36,0,0,0,0,0,0,0,32,0,0,0,192,15,0,0,119,111,114,100,47,119,101,98,83,101,116,116,105,110,103,115,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,235,108,72,101,203,89,214,1,238,250,204,211,133,90,214,1,33,210,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,11,0,36,0,0,0,0,0,0,0,16,0,0,0,132,16,0,0,119,111,114,100,47,95,114,101,108,115,47,10,0,32,0,0,0,0,0,1,0,24,0,241,53,89,80,51,88,214,1,9,27,200,210,224,89,214,1,224,14,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,32,109,238,80,233,249,193,147,123,0,0,0,155,0,0,0,29,0,36,0,0,0,0,0,0,0,32,0,0,0,173,16,0,0,119,111,114,100,47,95,114,101,108,115,47,102,111,111,116,110,111,116,101,115,46,120,109,108,46,114,101,108,115,10,0,32,0,0,0,0,0,1,0,24,0,87,230,96,67,203,89,214,1,188,141,29,133,232,89,214,1,241,53,89,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,14,109,238,80,32,16,105,98,121,1,0,0,100,6,0,0,19,0,36,0,0,0,0,0,0,0,32,0,0,0,99,17,0,0,91,67,111,110,116,101,110,116,95,84,121,112,101,115,93,46,120,109,108,10,0,32,0,0,0,0,0,1,0,24,0,69,165,107,47,203,89,214,1,146,47,242,210,133,90,214,1,198,192,88,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,0,0,24,104,236,80,0,0,0,0,0,0,0,0,0,0,0,0,6,0,36,0,0,0,0,0,0,0,16,0,0,0,13,19,0,0,95,114,101,108,115,47,10,0,32,0,0,0,0,0,1,0,24,0,217,231,88,80,51,88,214,1,237,204,199,210,224,89,214,1,198,192,88,80,51,88,214,1,80,75,1,2,63,0,20,0,0,0,8,0,23,109,238,80,42,73,130,205,226,0,0,0,76,2,0,0,11,0,36,0,0,0,0,0,0,0,32,0,0,0,49,19,0,0,95,114,101,108,115,47,46,114,101,108,115,10,0,32,0,0,0,0,0,1,0,24,0,153,114,232,58,203,89,214,1,96,71,139,59,203,89,214,1,217,231,88,80,51,88,214,1,80,75,5,6,0,0,0,0,12,0,12,0,143,4,0,0,60,20,0,0,0,0};
    // [END]

    std::wstring sTmpFilePath = sDirectory + L"/tmp";
    NSFile::CFileBinary oTmpFile;
    if (oTmpFile.CreateFileW(sTmpFilePath))
    {
        oTmpFile.WriteFile(template_binary, (DWORD)template_binary_len);
        oTmpFile.CloseFile();
    }

    COfficeUtils oUtils;
    bool bResult = (S_OK == oUtils.ExtractToDirectory(sTmpFilePath, sDirectory, NULL, 0)) ? true : false;

    NSFile::CFileBinary::Remove(sTmpFilePath);
    return bResult;
}

#endif // _FB2FILE_TEMPLATE_H
