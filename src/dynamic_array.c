#include <dynamic_array.h>
#include <stdlib.h>

DynamicArray *createDynamicArray(void **array, size_t size)
{
    DynamicArray *dynamicArray = (DynamicArray *)malloc(sizeof(DynamicArray));
    dynamicArray->array = array;
    dynamicArray->size = size;

    return dynamicArray;
}

// Add elements to the dynamic array
DynamicArray *appendElement(DynamicArray *dynamicArray, void *element)
{

    dynamicArray->array = realloc(dynamicArray->array, (dynamicArray->size + 1) * sizeof(dynamicArray->array[0]));

    dynamicArray->array[dynamicArray->size] = element;
    // TODO Revision needed
    // ! Not sure if this is correct
    dynamicArray->size++;

    return dynamicArray;
}

// Get the element at the specified index
void *getElement(DynamicArray *dynamicArray, size_t index)
{
    return dynamicArray->array[index];
}

// Delete last element from the dynamic array
DynamicArray *popElement(DynamicArray *dynamicArray)
{

    // TODO Revision needed
    // ! Not sure if this is correct
    free(dynamicArray->array[dynamicArray->size - 1]);
    dynamicArray->size--;
}

DynamicArray *deleteElement(DynamicArray *dynamicArray, size_t index)
{
    puts("Not implemented yet");
}

void freeDynamicArray(DynamicArray *dynamicArray)
{
    for (size_t i = 0; i < dynamicArray->size; i++)
    {
        free(dynamicArray->array[i]);
    }
    free(dynamicArray);
}
