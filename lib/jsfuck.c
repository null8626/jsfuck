#define __JSFUCK_C
#include <stdlib.h>
#include "jsfuck.h"

char * jsfuck(const char * code, const size_t length, size_t * size) {
    if (code == NULL || length == 0)
        return NULL;
    
    const jsfuck_input_t inp = { code, length };
    jsfuck_str_t * output = jsfuck_str_new(0xFFF);
    
    jsfuck_tokenizer_t * tokenizer = token_init(output, &inp);
    token_start(tokenizer);
    
    return jsfuck_str_trim(output, size);
}