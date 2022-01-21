#include <internal/stringutils.h>
#include <internal/common.h>
#include <internal/token.h>
#include <string.h>
#include <stddef.h>

#define JSFUCK_NAN         "[+[![]]]+[]+"
#define JSFUCK_TRUE        "[!![]]+[]+"
#define JSFUCK_FALSE       "[![]]+[]+"
#define JSFUCK_INFINITY    "[+(+!+[]+(!+[]+[])[!+[]+!+[]+!+[]]+[+!+[]]+[+[]]+[+[]]+[+[]])]+[]+"
#define JSFUCK_UNDEFINED   "[[][[]]]+[]+"

#define token_parse(tokenizer, string) _token_parse(tokenizer, string, sizeof(string) - 1)

static uint8_t _token_parse(jsfuck_tokenizer_t * ptr, const char * keyword, const uint8_t keyword_len) {
    if ((ptr->input.length - ptr->index) < keyword_len)
        return 0;
    
    uint8_t i = 0;
    for (0; i < keyword_len; i++) {
        if (*(ptr->input.input + ptr->index + i) != keyword[i]) {
            return 0;
        }
    }
    
    ptr->index += keyword_len;
    return 1;
}

void token_start(jsfuck_tokenizer_t * tokenizer) {
    do {
        if (token_parse(tokenizer, "NaN"))
            jsfuck_str_append(&tokenizer->str, JSFUCK_NAN);
        
        else if (token_parse(tokenizer, "true"))
            jsfuck_str_append(&tokenizer->str, JSFUCK_TRUE);
        
        else if (token_parse(tokenizer, "false"))
            jsfuck_str_append(&tokenizer->str, JSFUCK_FALSE);
        
        else if (token_parse(tokenizer, "Infinity"))
            jsfuck_str_append(&tokenizer->str, JSFUCK_INFINITY);
        
        else if (token_parse(tokenizer, "undefined"))
            jsfuck_str_append(&tokenizer->str, JSFUCK_UNDEFINED);
        
        else {
            jsfuck_get(tokenizer->input.input[tokenizer->index], &tokenizer->str);
            tokenizer->index++;
        }
    } while (tokenizer->index < tokenizer->input.length);
}
