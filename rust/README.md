# jsfuck
A quick and simple JSFuck obfuscator for Rust. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

## Example
```rs
use jsfuck;

fn main() {
    let jsfucked = jsfuck::obfuscate("0");
    
    // evaluate this as a JavaScript code and you should get "0"
    assert_eq!("[+[]]", jsfucked);
    
    let mut code = jsfuck::obfuscate("console.log('Hello, World!')");

    // wrap this with an eval()
    jsfuck::wrap_eval(&mut code);
    
    // paste this as a JavaScript code and it should print "Hello, World!"
    println!("{}", code);
}