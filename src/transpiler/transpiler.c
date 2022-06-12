// this is NOT a part of the library source.

#ifdef JSFUCK_SOURCE
#undef JSFUCK_SOURCE
#endif

#include "io.h"
#include <jsfuck.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fputs("error: please add a valid js file to transpile to.\n", stderr);
        return 1;
    }

    printf("reading %s...", argv[1]);

    file_contents_t f;

    if (!read_file(argv[1], &f))
    {
        putchar('\n');
        fputs("error: file does not exist.\n", stderr);
        return 1;
    }

    printf(" read %zu bytes.\ntranspiling...", f.file_size);

    char o_fn[455];
    o_fn[sprintf(o_fn, "jsfucked-%s", argv[1])] = 0;

    FILE *of = fopen(o_fn, "w");

    jsfuck_t jsf;
    jsf.input.value = f.contents;
    jsf.input.length = f.file_size;
    jsf.output.stream = of;
    jsf.flags = JSFUCK_FILE_STREAM | JSFUCK_WRAP_EVAL;

    jsfuck(&jsf);

    puts(" done.");

    free_file(&f);
    fclose(of);

    return 0;
}
