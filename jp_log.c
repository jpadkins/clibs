
///////////////////////////////////////////////////////////////////////////////
/// @file	jp_log.h
/// @author	Jacob Adkins (jpadkins)
/// @brief	API for logging information and possibly halting execution
///////////////////////////////////////////////////////////////////////////////
#include "jp_log.h"

///////////////////////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Defines
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Public functions
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
void jpLog__info(
        const char *file,
        const char *func,
        int line,
        const char *fmt,
        ...)
{
    va_list ap;

    fprintf(stdout, "[INFO][%s][%s][%d]: ", file, func, line);

    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    va_end(ap);

    fprintf(stdout, "\n");
}

///////////////////////////////////////////////////////////////////////////////
void jpLog__warn(
        const char *file,
        const char *func,
        int line,
        const char *fmt,
        ...)
{
    va_list ap;

    fprintf(stderr, "[WARN][%s][%s][%d]: ", file, func, line);

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    fprintf(stderr, "\n");
}

///////////////////////////////////////////////////////////////////////////////
void jpLog__exit(
        const char *file,
        const char *func,
        int line,
        const char *fmt,
        ...)
{
    va_list ap;

    fprintf(stderr, "[EXIT][%s][%s][%d]: ", file, func, line);

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    fprintf(stderr, "\n");

    exit(EXIT_FAILURE);
}

