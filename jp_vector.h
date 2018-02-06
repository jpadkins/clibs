
///////////////////////////////////////////////////////////////////////////////
/// @file	jp_vector.h
/// @author	Jacob Adkins (jpadkins)
/// @brief	Generic API for managing dynamic arrays in C99
///////////////////////////////////////////////////////////////////////////////
#ifndef JPA__VECTOR_H
#define JPA__VECTOR_H

///////////////////////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Functions
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Macros
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// @brief Initial maximum length of a jpVector
///////////////////////////////////////////////////////////////////////////////
#define JP_VECTOR_BASESIZE      (64)

///////////////////////////////////////////////////////////////////////////////
/// @brief Declare a new jpVector
///
/// @param type Data type of the jpVector's elements
///////////////////////////////////////////////////////////////////////////////
#define jpVector(type)\
    struct {\
        type *data;\
        size_t max;\
        size_t length;\
    }

///////////////////////////////////////////////////////////////////////////////
/// @brief Initializes a jpVector
///
/// This must be called on a newly declared jpVector before anything else.
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector_create(vec)\
    (\
        (vec).length = 0,\
        (vec).max = JP_VECTOR_BASESIZE,\
        (vec).data = calloc(JP_VECTOR_BASESIZE, sizeof(*(vec).data))\
    )

///////////////////////////////////////////////////////////////////////////////
/// @brief Frees the memory allocated for a jpVector
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector_destroy(vec)   ( free((vec).data), (vec).data = NULL )

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns the length of a jpVector (number of used elements)
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector_length(vec)    ( (vec).length )

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns the max length of a jpVector (number of allocated elements)
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector_max(vec)       ( (vec).max )

///////////////////////////////////////////////////////////////////////////////
/// @brief Expands the allocated size of a jpVector
///
/// Called internally by jpVector macros.
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector__expand(vec)\
    (\
        (vec).max += (vec).max / 2,\
        (vec).data = realloc((vec).data, sizeof(*(vec).data) * (vec).max)\
    )

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns the jpVector element at a particular index
///
/// @param vec      The jpVector
/// @param index    Index of the element
///////////////////////////////////////////////////////////////////////////////
#define jpVector_at(vec,index)  ( (vec).data[(index)] )

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns a pointer to the jpVector's data
///
/// @param vec  The jpVector
///////////////////////////////////////////////////////////////////////////////
#define jpVector_data(vec)      ( (vec).data )

///////////////////////////////////////////////////////////////////////////////
/// @brief Pushes a value into the jpVector
///
/// @param vec      The jpVector
/// @param value    The value to push
///////////////////////////////////////////////////////////////////////////////
#define jpVector_push(vec,value)\
    (\
        (vec).length == (vec).max ? jpVector__expand(vec) : 0,\
        (vec).data[(vec).length++] = (value)\
    )

///////////////////////////////////////////////////////////////////////////////
/// @brief Pops a value out of the jpVector
///
/// @param vec  The jpVector
/// @return The value popped
///////////////////////////////////////////////////////////////////////////////
#define jpVector_pop(vec) ( (vec).data[(vec).length--] )
            
///////////////////////////////////////////////////////////////////////////////
/// @brief Removes an entry at a particular index in the jpVector
///
/// @param vec      The jpVector
/// @param index    Index of the element to remove
///////////////////////////////////////////////////////////////////////////////
#define jpVector_erase(vec,index)\
    (\
        memmove(\
            (vec).data + (sizeof(*(vec).data) * index),\
            (vec).data + (sizeof(*(vec).data) * (index + 1)),\
            ((vec).length - index) * sizeof(*(vec).data)),\
        --(vec).length\
    )

// JPA__VECTOR_H
#endif
