#ifndef dynamic_array_h
#define dynamic_array_h

#include <stdlib.h>

typedef struct DynamicArray
{
    void **array;
    size_t size;
} DynamicArray;

/*
Create a new dynamic array
@param array: pointer to an array
@size: size of the array
*/
DynamicArray *createDynamicArray(void **array, size_t size);

/*
Add elements to the dynamic array
@param dynamicArray: pointer to a dynamic array
@param element: pointer to an element
*/
DynamicArray *appendElement(DynamicArray *dynamicArray, void *element);

// Get the element at the specified index
void *getElement(DynamicArray *dynamicArray, size_t index);

// Delete last element from the dynamic array
DynamicArray *popElement(DynamicArray *dynamicArray);

// Delete an element from the dynamic array
DynamicArray *deleteElement(DynamicArray *dynamicArray, size_t index);

void freeDynamicArray(DynamicArray *dynamicArray);

#endif
