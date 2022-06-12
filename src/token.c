#include <internal/common.h>
#include <internal/stream.h>
#include <internal/token.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define JSFUCK_NAN "[+[![]]]+[]"
#define JSFUCK_TRUE "[!![]]+[]"
#define JSFUCK_FALSE "[![]]+[]"
#define JSFUCK_INFINITY "[+(+!+[]+(!+[]+[])[!+[]+!+[]+!+[]]+[+!+[]]+[+[]]+[+[]]+[+[]])]+[]"
#define JSFUCK_UNDEFINED "[[][[]]]+[]"

#define token_parse(tokenizer, string) _token_parse(tokenizer, string, sizeof(string) - 1)

static bool _token_parse(jsfuck_tokenizer_t *ptr, const char *keyword, const uint8_t keyword_len)
{
    if ((ptr->jsfuck->input.length - ptr->index) < keyword_len)
    {
        return false;
    }

    for (uint8_t i = 0; i < keyword_len; i++)
    {
        if (*(ptr->jsfuck->input.value + ptr->index + i) != keyword[i])
        {
            return false;
        }
    }

    ptr->index += keyword_len;
    return true;
}

void jsfuck_token_parse(jsfuck_tokenizer_t *tokenizer)
{
jsfuck_token_parse_loop:
    if (token_parse(tokenizer, "NaN"))
    {
        jsfuck_stream_push(tokenizer->jsfuck, JSFUCK_NAN);
    }
    else if (token_parse(tokenizer, "true"))
    {
        jsfuck_stream_push(tokenizer->jsfuck, JSFUCK_TRUE);
    }
    else if (token_parse(tokenizer, "false"))
    {
        jsfuck_stream_push(tokenizer->jsfuck, JSFUCK_FALSE);
    }
    else if (token_parse(tokenizer, "Infinity"))
    {
        jsfuck_stream_push(tokenizer->jsfuck, JSFUCK_INFINITY);
    }
    else if (token_parse(tokenizer, "undefined"))
    {
        jsfuck_stream_push(tokenizer->jsfuck, JSFUCK_UNDEFINED);
    }
    else
    {
        jsfuck_get(tokenizer->jsfuck->input.value[tokenizer->index], tokenizer->jsfuck);
        tokenizer->index++;
    }

    if (tokenizer->index < tokenizer->jsfuck->input.length)
    {
        jsfuck_stream_push(tokenizer->jsfuck, "+");
        goto jsfuck_token_parse_loop;
    }
}
