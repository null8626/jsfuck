#pragma once

#include <windows.h>

#define JSFUCK_VERSION "v1.0"
#define JSFUCK_VERSION_RAW 1, 0, 0, 0

#define JSFUCK_AUTHOR "null (https://github.com/null8626)"
#define JSFUCK_INTERNAL_NAME "jsfuck"

#ifdef JSFUCK_TRANSPILER
#define JSFUCK_LEGAL_COPYRIGHT "Copyleft 2021-2022 null - Licensed under GPL v3."
#else
#define JSFUCK_LEGAL_COPYRIGHT "Licensed under the MIT license."
#endif

#ifdef JSFUCK_TRANSPILER
#define JSFUCK_NAME "JSFuck transpiler v1.0"
#define JSFUCK_DESCRIPTION "A transpiler that transpiles JSFuck code to plain JavaScript."
#define JSFUCK_TYPE VFT_APP
#define JSFUCK_ORIGINAL_FILENAME "jsfuck.exe"
#else
#define JSFUCK_NAME "JSFuck C/C++ dynamic-link library v1.0"
#define JSFUCK_DESCRIPTION "A C/C++ library that helps developers obfuscate JavaScript code using JSFuck."
#define JSFUCK_TYPE VFT_DLL
#define JSFUCK_ORIGINAL_FILENAME "jsfuck.dll"
#endif

#define IDI_JSFUCK_ICON 100
