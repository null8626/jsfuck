#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "io.h"

void free_file(file_contents_t f) {
    if (f->file_size != 0)
        free(f->contents);
    
    free(f);
}

file_contents_t read_file(const char * filename) {
    FILE * fp = fopen(filename, "r");
    
    if (fp == NULL)
        return NULL;
    
    file_contents_t out = malloc(sizeof(_file_contents_t));
    out->file_size = 0;
    fseek(fp, 0, SEEK_END);
    
    out->file_size = (uint64_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    out->contents = malloc(out->file_size);
    fread(out->contents, out->file_size, 1, fp);
    fclose(fp);
    
    return out;
}