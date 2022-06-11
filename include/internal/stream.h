#ifndef __JSFUCK_STRING_H
#define __JSFUCK_STRING_H

#include "../jsfuck.h"
#include <stdbool.h>
#include <stdint.h>

#define jsfuck_stream_push(jsf, string) _jsfuck_stream_push(jsf, string, sizeof(string) - 1)

#ifdef __cplusplus
extern "C"
{
#endif

    void _jsfuck_stream_push(jsfuck_t *data, char *str, const size_t size);
    void jsfuck_stream_finalize(jsfuck_t *ptr);

#ifdef __cplusplus
}
#endif
#endif