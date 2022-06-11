#include <internal/token.h>
#include <jsfuck.h>
#include <stdlib.h>

#define JSFUCK_EVAL_HEADER                                                                                             \
    "[][(![]+[])[+[]]+(![]+[])[!+[]+!+[]]+(![]+[])[+!+[]]+(!![]+[])[+[]]][([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]" \
    "]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[][(" \
    "![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[" \
    "+!+[]]])[+!+[]+[+[]]]+([][[]]+[])[+!+[]]+(![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[+!+[]]+([][[]]+[])[+[" \
    "]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!" \
    "![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!" \
    "+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+(!![]+[])[+!+[]]]("
#define JSFUCK_EVAL_FOOTER ")()"

JSFUCK_EXPORT void jsfuck(jsfuck_t *jsf)
{
    jsfuck_tokenizer_t tokenizer = {jsf, 0};

    if (jsf->flags & JSFUCK_STATIC_STRING || jsf->flags & JSFUCK_MALLOC_STRING)
    {
        jsf->output.str.length = 0;
    }

    if (jsf->flags & JSFUCK_WRAP_EVAL)
    {
        jsfuck_stream_push(jsf, JSFUCK_EVAL_HEADER);
    }

#ifdef _WIN32
    if (jsf->flags & JSFUCK_FILE_DESCRIPTOR)
    {
        jsf->output.stream = _fdopen(jsf->output.fd, "w");
        jsf->flags ^= JSFUCK_FILE_DESCRIPTOR;
        jsf->flags |= JSFUCK_FILE_STREAM;
    }
#endif

    jsfuck_token_parse(&tokenizer);

    if (jsf->flags & JSFUCK_WRAP_EVAL)
    {
        jsfuck_stream_push(jsf, JSFUCK_EVAL_FOOTER);
    }

    jsfuck_stream_finalize(jsf);
}
