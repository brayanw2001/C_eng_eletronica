#include "float_vector.h" //inclusão de bibliotecas não padrões devem possuir "" em vez de <>
#include<stdlib.h>

struct FloatVector
{
    int capacity;
    int size;
    float *data;
};
/**
 * @brief aloca um vetor de float com uma dada capacidade
 * 
 * @param capacity capacidade do vetor para data
 * @return FloatVector* um vetor de floats alocados, sua capacidade e seu tamanho
 */
FloatVector* create(int capacity)
{
    FloatVector* vec = (FloatVector*)calloc(1, sizeof(FloatVector));
    vec->capacity = 0;
    vec->size = 0;
    vec->data = (int*)calloc(capacity, sizeof(int));
    return vec;
}

void destroy(FloatVector** vec_ref)
{
    FloatVector *vec = *vec_ref;

    // de dentro para fora
    free(vec->data);
    free(vec);
    free(vec);
    *vec_ref = NULL;
}