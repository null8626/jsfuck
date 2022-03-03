mod token;
use token::Tokenizer;

pub fn jsfuck(input: String) -> String {
    let mut output = String::new();
    
    if input.len() == 0 {
        return output;
    }
    
    let mut tokenizer = Tokenizer::new(&input);
    tokenizer.parse(&mut output);
    
    output
}