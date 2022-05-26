# libjsfuck
JSFuck C/C++ obfuscator and transpiler. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

### Library Usage

Returning a `malloc`ed null-terminated string:

```c
#include <jsfuck.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char code[] = "console.log('Hello, World!');";

  jsfuck_t jsf;
  
  jsf.input.value = code;
  jsf.input.length = 29;
  jsf.flags = JSFUCK_MALLOC_STRING | JSFUCK_NULL_TERMINATE | JSFUCK_WRAP_EVAL;

  jsfuck(&jsf);
  
  printf("length of output string: %lld\n", jsf.output.str.length);
  printf("%s\n", jsf.output.str.value);

  free(jsf.output.str.value); // you are responsible for free-ing it! remember!
  
  return 0;
}
```

Or, if you are not a fan of `malloc` for some reason:

```c
#include <jsfuck.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char code[] = "console.log('Hello, World!');";

  // warning: output strings tend to be HUGE!
  char output[50000];

  jsfuck_t jsf;
  
  jsf.input.value = code;
  jsf.input.length = 29;
  jsf.output.value = output;
  jsf.output.capacity = 50000;
  jsf.flags = JSFUCK_STATIC_STRING | JSFUCK_NULL_TERMINATE | JSFUCK_WRAP_EVAL;

  jsfuck(&jsf);
  
  printf("amount of bytes copied to output: %lld\n", jsf.output.str.length);
  printf("%s\n", jsf.output.str.value);

  return 0;
}
```

Writing to a file:

```c
#include <jsfuck.h>
#include <stdio.h>

int main(void) {
  char code[] = "console.log('Hello, World!');";

  FILE * file = fopen("gibberish.js", "w");
  if (file == NULL) {
    return 1;
  }

  jsfuck_t jsf;
  
  jsf.input.value = code;
  jsf.input.length = 29;
  jsf.output.stream = file;
  jsf.flags = JSFUCK_FILE_STREAM | JSFUCK_WRAP_EVAL;

  jsfuck(&jsf);

  fclose(file);
  return 0;
}
```

### Building locally

- Linux
```
make [...]
```
- macOS
```
make -f Macfile [...]
```
- Windows (GCC)
```
make WIN=yes [...]
```
- Windows (MSVC)
```
nmake /nologo /f VSMakefile [...]
```
- Windows (Clang)
```
nmake /nologo /f VSClangMakefile [...]
```

#### Additional optional arguments

| Format name | Description | Possible values |
|----|----|----|
| `CC` | The compiler used. `VSMakefile` and `VSClangMakefile` ignores this. | `gcc` (default), `clang` |
| `SHARED` | Whether to produce a shared/dynamic library. | `no` (default), `yes` |
