/*
 * array_typed.h
 *
 *  Created on: Sep 12, 2013
 *      Author: mgrosvenor
 */


#include "../../types/types.h"
#include "array.h"

typedef ch_word (*cmp_void_f)(void*, void*);

#define declare_array(TYPE)\
\
struct ch_array_##TYPE;\
typedef struct ch_array_##TYPE  ch_array_##TYPE##_t;\
\
struct ch_array_##TYPE{\
    ch_word size;  /*Return the max number number of elements in the array list*/\
    TYPE* first; /*Pointer to the fist valid entry list. Not valid if first == end*/\
    TYPE* last; /*Pointer to the last valid element in the array. Not valid if last == end*/\
    TYPE* end; /*Pointer to the one element beyond the end of the valid elements in array. Do not dereference! */\
\
    void (*resize)(ch_array_##TYPE##_t* this, ch_word new_size); /*Resize the array*/\
    ch_word (*eq)(ch_array_##TYPE##_t* this, ch_array_##TYPE##_t* that); /*Check for equality*/\
\
    TYPE* (*off)(ch_array_##TYPE##_t* this, ch_word idx); /*Return the element at a given offset, with bounds checking*/\
    TYPE* (*next)(ch_array_##TYPE##_t* this, TYPE* ptr);  /*Step forwards by one entry*/\
    TYPE* (*prev)(ch_array_##TYPE##_t* this, TYPE* ptr); /*Step backwards by one entry*/\
    TYPE* (*forward)(ch_array_##TYPE##_t* this, TYPE* ptr, ch_word amount);  /*Step forwards by amount*/\
    TYPE* (*back)(ch_array_##TYPE##_t* this, TYPE* ptr, ch_word amount);  /*Step backwards by amount*/\
\
    TYPE* (*find)(ch_array_##TYPE##_t* this, TYPE* begin, TYPE* end, TYPE value); /*find the given value using the comparator function*/\
    void (*sort)(ch_array_##TYPE##_t* this); /*sort into order given the comparator function*/\
\
    void (*delete)(ch_array_##TYPE##_t* this); /*Free the resources associated with this array, assumes that individual items have been freed*/\
\
    TYPE* (*from_carray)(ch_array_##TYPE##_t* this, TYPE* carray, ch_word count); /*Set at most count elements to the value in carray starting at offset in this array*/\
\
    ch_array_t* _array;\
};\
\
ch_array_##TYPE##_t* ch_array_##TYPE##_new(ch_word size, ch_word (*cmp)(TYPE* lhs, TYPE* rhs) );\

