#include <internal/stringutils.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifndef JSFUCK_PADDING
#define JSFUCK_PADDING 0x1000
#endif

void _jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const uint16_t length) {
  ptr->size += length;

  if (ptr->limit <= ptr->size) {
    ptr->limit = JSFUCK_PADDING * (uint64_t)ceilf((float)(ptr->limit) / (float)(JSFUCK_PADDING));
    ptr->data = realloc(ptr->data, ptr->limit);
  }

  memcpy(ptr->data + ptr->size - length, new_str, length);
}

void jsfuck_str_new(jsfuck_str_t * s) {
  s->data = malloc(JSFUCK_PADDING);
  s->limit = JSFUCK_PADDING;
  s->size = 0;
}

char * jsfuck_str_dispose(jsfuck_str_t * ptr, uint64_t * s, const bool null_terminated) {
  ptr->size--; // remove last +
  
  if (s != NULL) {
    *s = ptr->size;
  }

  char * res;

  if (null_terminated) {
    res = realloc(ptr->data, ptr->size + 1);
    res[ptr->size] = 0;
  } else {
    res = realloc(ptr->data, ptr->size);
  }
  
  return res;
}