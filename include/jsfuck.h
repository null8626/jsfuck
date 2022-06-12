#ifndef __JSFUCK_H
#define __JSFUCK_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef JSFUCK_DLL
#ifdef JSFUCK_SOURCE
#define JSFUCK_EXPORT __declspec(dllexport)
#else
#define JSFUCK_EXPORT __declspec(dllimport)
#endif
#else
#define JSFUCK_EXPORT
#endif

#define JSFUCK_STATIC_STRING 1
#define JSFUCK_MALLOC_STRING 2
#define JSFUCK_INPUT_WSTRING 4
#define JSFUCK_FILE_STREAM 8
#define JSFUCK_FILE_DESCRIPTOR 16
#define JSFUCK_NULL_TERMINATE 32
#define JSFUCK_WRAP_EVAL 64

#define JSFUCK_NULL_STRING JSFUCK_STATIC_STRING

    typedef unsigned char jsfuck_flags_t;

    typedef struct
    {
        struct
        {
            char *value;
            size_t length;
        } input;
        union {
            struct
            {
                char *value;
                size_t length;
                size_t capacity;
            } str;
            FILE *stream;
            int fd;
        } output;
        jsfuck_flags_t flags;
    } jsfuck_t;

#ifndef _JSFUCK_INTERNAL
    JSFUCK_EXPORT void jsfuck(jsfuck_t *data);
#endif

#ifdef __cplusplus
}
#endif
#endif