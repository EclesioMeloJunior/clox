#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "value.h"
#include "object.h"

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
    switch(value.type) {
        case VAL_BOOL:
            printf(AS_BOOL(value) ? "true" : "false"); break;
        case VAL_NIL:
            printf("nil"); break;
        case VAL_NUMBER:
            printf("%g", AS_NUMBER(value)); break;
        case VAL_OBJ:
            printObject(value); break;
    }
}

bool valuesEqual(Value a, Value b) {
    if (a.type != b.type) return false;
    switch (a.type) {
        case VAL_BOOL:
            return AS_BOOL(a) == AS_BOOL(b);
        case VAL_NIL:
            return true;
        case VAL_NUMBER:
            return AS_NUMBER(a) == AS_NUMBER(b);
        case VAL_OBJ:
            return AS_OBJ(a) == AS_OBJ(b);
        default: return false;
    }
}

