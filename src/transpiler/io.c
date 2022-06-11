#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void free_file(file_contents_t *f)
{
    if (f->file_size != 0)
        free(f->contents);
}

bool read_file(const char *filename, file_contents_t *f)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        return false;

    f->file_size = 0;
    fseek(fp, 0, SEEK_END);

    f->file_size = (size_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);

    f->contents = malloc(f->file_size);
    fread(f->contents, f->file_size, 1, fp);
    fclose(fp);

    return true;
}