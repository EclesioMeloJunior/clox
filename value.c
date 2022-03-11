#include <stdio.h>

#include "memory.h"
#include "value.h"

void initValueArray(ValueArray* slice) {
    slice->capacity = 0;
    slice->count = 0;
    slice->values = NULL;
}

void writeValueArray(ValueArray* slice, Value value) {
    if(slice->capacity < slice->count + 1) {
        int oldCapacity = slice->capacity;
        slice->capacity = GROW_CAPACITY(oldCapacity);
        slice->values = GROW_ARRAY(Value, slice->values, 
            oldCapacity, slice->capacity);
    }

    slice->values[slice->count] = value;
    slice->count++;
}

void freeValueArray(ValueArray* slice) {
    FREE_ARRAY(Value, slice->values, slice->capacity);
    initValueArray(slice);
}

void printValue(Value value) {
    printf("%g", value);
}