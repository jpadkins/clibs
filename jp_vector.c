
///////////////////////////////////////////////////////////////////////////////
/// @file	jp_vector.c
/// @author	Jacob Adkins (jpadkins)
/// @brief	Generic API for managing dynamic arrays in C99
///////////////////////////////////////////////////////////////////////////////
#include "vector.h"

///////////////////////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////////////////////
#include <string.h>

#ifndef JP_NOLOG
#include "jp_log.h"
#endif

///////////////////////////////////////////////////////////////////////////////
// Public functions
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
void cfVector__erase(char *data, size_t length, size_t size, size_t index)
{
#ifndef JP_NOLOG
    jpLog_exitIf(!data, "NULL argument");
#endif

    for (size_t i = index * size; i < (length - 1) * size; i += size) {
        memcpy(data + i, data + i + size, size);
    }
}

