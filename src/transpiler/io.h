#ifndef JSFUCK_C_IO_H
#define JSFUCK_C_IO_H

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    size_t file_size;
    char *contents;
} file_contents_t;

#ifdef __cplusplus
extern "C"
{
#endif

    void free_file(file_contents_t *f);
    bool read_file(const char *filename, file_contents_t *f);

#ifdef __cplusplus
}
#endif
#endif
