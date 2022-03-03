#ifndef __JSFUCK_H
#define __JSFUCK_H

#include <stdint.h>

char * jsfuck(const char * code, const uint64_t length, uint64_t * size);

#endif