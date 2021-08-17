#define __JSFUCK_C
#include "jsfuck.h"

char * jsfuck(const char * code, const size_t length) {
    if (!strlen(code) || !length)
        return "";
    
    const jsfuck_input_t inp = { code, length };
    jsfuck_str_t * output = jsfuck_str_new();
    
    jsfuck_tokenizer_t * tokenizer = token_init(output, &inp);
    token_start(tokenizer);
    
    return jsfuck_str_trim(output);
}