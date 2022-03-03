#ifndef __JSFUCK_TOKEN_H
#define __JSFUCK_TOKEN_H

#include <internal/stringutils.h>

typedef struct {
    jsfuck_str_t str;
    
    const struct {
        const char * input;
        const uint64_t length;
    } input;
    
    uint64_t index;
} jsfuck_tokenizer_t;

void token_start(jsfuck_tokenizer_t * tokenizer);

#endif
