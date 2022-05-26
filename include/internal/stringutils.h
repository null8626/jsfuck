#ifndef __JSFUCK_STRING_H
#define __JSFUCK_STRING_H

#include <stdbool.h>
#include <stdint.h>

#define jsfuck_str_append(tokenizer, string) _jsfuck_str_append(tokenizer, string, sizeof(string) - 1)

typedef struct {
  char * data;
  uint64_t size;
  uint64_t limit;
} jsfuck_str_t;

#ifdef __cplusplus
extern "C" {
#endif

void _jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const uint16_t length);
void jsfuck_str_new(jsfuck_str_t * ptr);
char * jsfuck_str_dispose(jsfuck_str_t * ptr, uint64_t * s, const bool null_terminated);

#ifdef __cplusplus
}
#endif
#endif