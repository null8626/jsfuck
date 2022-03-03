pub mod token;
use token::Tokenizer;

pub fn jsfuck(input: String) -> String {
    if input.len() == 0 {
        return String::new();
    }
    
    let mut tokenizer = Tokenizer::new(&input);
    
    tokenizer.parse()
}