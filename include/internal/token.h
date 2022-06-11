#ifndef __JSFUCK_TOKEN_H
#define __JSFUCK_TOKEN_H

#ifndef _JSFUCK_INTERNAL
#define _JSFUCK_INTERNAL
#endif

#include "../jsfuck.h"
#include "stream.h"

typedef struct
{
    jsfuck_t *jsfuck;
    size_t index;
} jsfuck_tokenizer_t;

#ifdef __cplusplus
extern "C"
{
#endif

    void jsfuck_token_parse(jsfuck_tokenizer_t *tokenizer);

#ifdef __cplusplus
}
#endif
#endif
