#include <internal/stream.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef JSFUCK_PADDING
#define JSFUCK_PADDING 0x1000
#endif

#ifdef _WIN32
#define jsfuck_write _write
#else
#define jsfuck_write write
#endif

void _jsfuck_stream_push(jsfuck_t * data, char * str, const uint64_t length) {
  if (data->flags & JSFUCK_STATIC_STRING) {
    data->output.str.length += length;

    if (data->output.str.capacity > data->output.str.length) {
      memcpy(data->output.str.value + data->output.str.length - length, str, length);
    }
  } else if (data->flags & JSFUCK_MALLOC_STRING) {
    data->output.str.length += length;

    if (data->output.str.capacity <= data->output.str.length) {
      data->output.str.capacity = JSFUCK_PADDING * (uint64_t)ceilf((float)(data->output.str.capacity) / (float)(JSFUCK_PADDING));
      data->output.str.value = (char *)realloc(data->output.str.value, data->output.str.capacity);
    }
  
    memcpy(data->output.str.value + data->output.str.length - length, str, length);
  } else if (data->flags & JSFUCK_FILE_STREAM) {
    fwrite(str, 1, length, data->output.stream);
  } else {
    jsfuck_write(data->output.fd, str, length);
  }
}

void jsfuck_stream_finalize(jsfuck_t * ptr) {
  if (ptr->flags & JSFUCK_MALLOC_STRING) {
    ptr->output.str.value = realloc(ptr->output.str.value, ptr->output.str.length - ((ptr->flags & JSFUCK_NULL_TERMINATE) == 0));
  }

  if (ptr->flags & JSFUCK_NULL_TERMINATE && (ptr->flags & JSFUCK_MALLOC_STRING || (ptr->flags & JSFUCK_STATIC_STRING && (ptr->output.str.length + 1) < ptr->output.str.capacity))) {
    ptr->output.str.value[ptr->output.str.length] = 0;
  }
}