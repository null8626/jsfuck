# jsfuck
A quick and simple JSFuck obfuscator for Rust. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com).

## Quick example:
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

## Use the tokenizer!
```rs
use jsfuck::token::Tokenizer;

fn main() {
    let my_input = String::from("Hello!");
    let mut jsfuck = Tokenizer::new(&my_input);

    // parse it and print the obfuscated output
    println!("{}", jsfuck.parse());
    
    // reuse this instance with another string
    let another_input = String::from("Goodbye!");
    jsfuck.change_with(&another_input);
    
    // this should output the jsfucked version of "Goodbye!"
    println!("{}", jsfuck.parse());
}
```