#include <internal/token.h>
#include <stdlib.h>
#include <jsfuck.h>

char * jsfuck(const char * code, const uint64_t length, uint64_t * size) {
    if (code == NULL || length == 0) {
        return NULL;
    }
    
    jsfuck_tokenizer_t tokenizer = {
        {
            malloc(JSFUCK_PADDING), 0,
            JSFUCK_PADDING, JSFUCK_PADDING
        }, {
            code, length
        }, 0 
    };
    
    token_start(&tokenizer);
    
    return jsfuck_str_trim(&tokenizer.str, size);
}
