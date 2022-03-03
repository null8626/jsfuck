#ifndef __JSFUCK_STRING_H
#define __JSFUCK_STRING_H

#include <stdint.h>

#define jsfuck_str_append(tokenizer, string) _jsfuck_str_append(tokenizer, string, sizeof(string) - 1)

typedef struct {
    char * data;
    uint64_t size;
    uint64_t limit;
    uint16_t padding;
} jsfuck_str_t;

void _jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const uint16_t length);
char * jsfuck_str_trim(jsfuck_str_t * ptr, uint64_t * s);

#endif