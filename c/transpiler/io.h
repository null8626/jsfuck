#ifndef JSFUCK_C_IO_H
#define JSFUCK_C_IO_H

#include <stdint.h>

typedef struct {
    uint64_t file_size;
    char * contents;
} _file_contents_t, * file_contents_t;

void free_file(file_contents_t f);
file_contents_t read_file(const char * filename);

#endif