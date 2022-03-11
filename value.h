#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* slice);
void writeValueArray(ValueArray* slice, Value value);
void freeValueArray(ValueArray* slice);
void printValue(Value value);

#endif