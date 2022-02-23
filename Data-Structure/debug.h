#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#if DEBUG
#define debug(msg)                                                             \
    do {                                                                       \
    printf("[debug]: %s ,line: %i, file: %s, func: %s \n", msg, __LINE__,      \
    __FILE__, __FUNCTION__);                                                   \
    } while (false)
#else
#define debug(msg)                                                             \
    do {                                                                       \
    } while (false)
#endif

#if DEBUG
#define trace(msg, ...)                                                        \
    do {                                                                       \
    printf("[trace]: (%i)::%s::%s::%s " msg, __LINE__, __FILE__, __FUNCTION__,     \
    __VA_ARGS__);                                                              \
    } while (false)
#else
#define trace(msg, ...)                                                        \
    do {                                                                       \
    } while (false)
#endif

