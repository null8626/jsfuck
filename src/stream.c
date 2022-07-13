#include <internal/stream.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JSFUCK_PADDING
#define JSFUCK_PADDING 0x1000
#endif

#if defined(_WIN32) || defined(__APPLE__)
#include <math.h>
#define jsfuck_ceilf(x) (size_t) ceilf(x)
#else
typedef union {
    float f;
    unsigned int i;
} jsfuck_float_t;

static size_t jsfuck_ceilf(float x)
{
    jsfuck_float_t f;
    f.f = x;

    unsigned int exponent = ((f.i & 0x7fffffff) >> 23) - 127;
    unsigned int mantissa = f.i & 0x7fffff;

    if (exponent < 0)
    {
        return x > 0.0f;
    }
    else
    {
        const unsigned int mask = 0x7fffff >> exponent;

        if ((mantissa & mask) == 0)
        {
            return (size_t)x;
        }
        else
        {
            mantissa += 1 << (23 - exponent);

            if (mantissa & 0x800000)
            {
                mantissa = 0;
            }

            mantissa &= ~mask;
        }
    }

    f.i = 0x80000000 | ((exponent + 127) << 23) | mantissa;

    return (size_t)f.f;
}
#endif

void _jsfuck_stream_push(jsfuck_t *data, char *str, const size_t length)
{
    data->output.str.length += length;

    if (data->flags & JSFUCK_STATIC_STRING && data->output.str.value != NULL &&
        data->output.str.capacity > data->output.str.length)
    {
        memcpy(data->output.str.value + data->output.str.length - length, str, length);
    }
    else if (data->flags & JSFUCK_MALLOC_STRING)
    {
        if (data->output.str.capacity <= data->output.str.length)
        {
            data->output.str.capacity =
                JSFUCK_PADDING * jsfuck_ceilf((float)(data->output.str.length) / (float)(JSFUCK_PADDING));
            data->output.str.value = (char *)realloc(data->output.str.value, data->output.str.capacity);
        }

        memcpy(data->output.str.value + data->output.str.length - length, str, length);
    }
    else if (data->flags & JSFUCK_FILE_STREAM)
    {
        fwrite(str, 1, length, data->output.stream);
    }

#ifndef _WIN32
    else
    {
        write(data->output.fd, str, length);
    }
#endif
}

void jsfuck_stream_finalize(jsfuck_t *ptr)
{
    if (ptr->output.str.value == NULL)
    {
        return;
    }

    if (ptr->flags & JSFUCK_MALLOC_STRING)
    {
        ptr->output.str.value =
            realloc(ptr->output.str.value, ptr->output.str.length - ((ptr->flags & JSFUCK_NULL_TERMINATE) == 0));
    }

    if (ptr->flags & JSFUCK_NULL_TERMINATE &&
        (ptr->flags & JSFUCK_MALLOC_STRING ||
         (ptr->flags & JSFUCK_STATIC_STRING && (ptr->output.str.length + 1) < ptr->output.str.capacity)))
    {
        ptr->output.str.value[ptr->output.str.length] = 0;
    }
}
