# jsfuck
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
  jsf.output.str.value = output;
  jsf.output.str.capacity = 50000;
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

### Download

Prebuilt (64-bit) binaries are available.

- [Windows](https://github.com/null8626/jsfuck/releases/download/v1.1.0/jsfuck-windows.zip)
- [macOS](https://github.com/null8626/jsfuck/releases/download/v1.1.0/jsfuck-macos.zip)
- [Linux](https://github.com/null8626/jsfuck/releases/download/v1.1.0/jsfuck-linux.zip)

### Building with CMake

To create the build files:

```console
cmake -B build .
cmake build
```

And then:

- For POSIX:

```console
cd build
make
```

- For Windows:

```console
msbuild build/jsfuck.sln -noLogo -p:Configuration=Release
```

And the library files should be there in the `build/Release` directory.
