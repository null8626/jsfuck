#ifndef __JSFUCK_COMMON_H
#define __JSFUCK_COMMON_H

#ifndef _JSFUCK_INTERNAL
#define _JSFUCK_INTERNAL
#endif

#include "../jsfuck.h"
#include "token.h"

#ifdef __cplusplus
extern "C"
{
#endif

    void jsfuck_get(const char c, jsfuck_t *s);

#ifdef __cplusplus
}
#endif
#endif