# jsfuck.h
JSFuck obfuscator written in ANSI C. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com). Tested on MinGW (Windows) and GCC (Linux).

### Build
To build this library, you can clone the repo, compile every C source to an object file, and turn the object files to a static library file or a dynamic library file.

### Example
```c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "jsfuck.h"

int main() {
    char code[] = "hello";
    char * output = jsfuck(code, strlen(code));
    
    printf("%s\n", output);
    free(output);
    
    return 0;
}
```
