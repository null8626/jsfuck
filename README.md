# libjsfuck
JSFuck obfuscator for C/C++ and Rust. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

### Building
<details>
<summary>C/C++ library</summary>

- GCC
```
make
```
- MinGW
```
make OS=WIN
```
- MSVC
```
.\vcbuild.bat
```

</details>

<details>
<summary>Rust library</summary>

```
cargo build
```

</details>

### Library Usage
<details>
<summary>C/C++ library</summary>

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

Tip: You can use `NULL` for the third argument if determining output size is not necessary.
</details>

<details>
<summary>Rust library</summary>

## Example

```rs
use jsfuck;

fn main() {
    let jsfucked = jsfuck::obfuscate("0");
    
    // evaluate this as a JavaScript code and you should get "0"
    assert_eq!(String::from("[+[]]+[]"), jsfucked);
    
    let mut code = jsfuck::obfuscate("console.log('Hello, World!')");

    // wrap this with an eval()
    jsfuck::wrap_eval(&mut code);
    
    // paste this as a JavaScript code and it should print "Hello, World!"
    println!("{}", code);
}
```

</details>

### License
- The C/C++ and Rust library are distributed under the [MIT License](https://opensource.org/licenses/MIT).
- The libjsfuck transpiler is distributed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).