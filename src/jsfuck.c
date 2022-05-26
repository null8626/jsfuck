#include <internal/token.h>
#include <stdlib.h>
#include <jsfuck.h>

#define JSFUCK_EVAL_HEADER "[][(![]+[])[+[]]+(![]+[])[!+[]+!+[]]+(![]+[])[+!+[]]+(!![]+[])[+[]]][([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+([][[]]+[])[+!+[]]+(![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[+!+[]]+([][[]]+[])[+[]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+(!![]+[])[+!+[]]]("
#define JSFUCK_EVAL_FOOTER ")()"

JSFUCK_EXPORT void jsfuck(jsfuck_t * jsf) {
  jsfuck_tokenizer_t tokenizer = { jsf, 0 };

  if (jsf->flags & JSFUCK_STATIC_STRING || jsf->flags & JSFUCK_MALLOC_STRING) {
    jsf->output.str.length = 0;
  }

  if (jsf->flags & JSFUCK_WRAP_EVAL) {
    jsfuck_stream_push(jsf, JSFUCK_EVAL_HEADER);
  }

  jsfuck_token_parse(&tokenizer);

  if (jsf->flags & JSFUCK_WRAP_EVAL) {
    jsfuck_stream_push(jsf, JSFUCK_EVAL_FOOTER);
  }

  jsfuck_stream_finalize(jsf);
}
