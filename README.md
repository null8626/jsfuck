# libjsfuck
JSFuck obfuscator written in ANSI C. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

### Build
- GCC
```
make
```
- MinGW
```
make.exe OS=WIN
```
- MSVC
```
.\vcbuild.bat
```

### Library Usage
```c
#include <jsfuck.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    uint64_t output_size;

    char code[] = "hello";
    char * output = jsfuck(code, 5, &output_size);
    
    printf("length of output string: %lld\n", output_size);
    printf("%s\n", output);
    free(output);
    
    return 0;
}
```
Pro Tip: You can use `NULL` for the third argument if determining output size is not necessary.

### License
- The C/C++ library is distributed under the [MIT License](https://opensource.org/licenses/MIT).
- The jsfuck.h transpiler is distributed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
