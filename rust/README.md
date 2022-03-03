# jsfuck
A quick and simple JSFuck obfuscator for Rust. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

The library only exports one single function.
```rs
pub fn jsfuck(input: String) -> String { /* ... */ }
```

## Example
```rs
use jsfuck::jsfuck;

fn main() {
    let jsfucked = jsfuck(String::from("0"));
    
    // evaluate this as a JavaScript code and you should get "0"
    assert_eq!("[+[]]", jsfucked);
    
    // warning: huge string incoming!
    println!("{}", jsfuck(String::from("Hello, World!")));
}
```