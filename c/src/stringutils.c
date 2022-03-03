#include <internal/stringutils.h>
#include <string.h>
#include <stdlib.h>

void _jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const uint16_t length) {
    ptr->size += length;
    while (ptr->limit <= ptr->size) {
        ptr->limit += ptr->padding;
        ptr->data = realloc(ptr->data, ptr->limit);
    }

    memcpy(ptr->data + ptr->size - length, new_str, length);
}

char * jsfuck_str_trim(jsfuck_str_t * ptr, uint64_t * s) {
    ptr->size--;
    
    char * output = malloc(ptr->size);
    memcpy(output, ptr->data, ptr->size);
    output[ptr->size] = 0;

    if (s != NULL) {
        *s = ptr->size;
    }
    
    free(ptr->data);
    return output;
}