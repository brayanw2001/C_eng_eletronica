#include "float_vector.h" //inclusão de bibliotecas não padrões devem possuir "" em vez de <>
#include<stdlib.h>
#include<stdio.h>

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
    vec->capacity = capacity;
    vec->size = 0;
    vec->data = (float*)calloc(capacity, sizeof(float));
    return vec;
}

void destroy(FloatVector** vec_ref)         // quando quero modificar um int dentro de uma função, um ponteiro deve ser usado como parametro, e um endereço de inteiro deve ser recebido
{                                           // quando quero modificar um ponteiro, um ponteiro para esse ponteiro deve ser usado, e o endereço do ponteiro deve ser recebido pela função
    FloatVector* vec = *vec_ref;

    // de dentro para fora
    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void append(FloatVector *vec, float val)
{
    if (vec->size == vec->capacity)
    {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full'\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size] = val; // poderia ser resumido à     vec->data[vec->size++] = val;
    vec->size++;
}

void print(const FloatVector *vec)
{
    printf("Capacity: %d\n", vec->capacity);
    printf("Size: %d\n", vec->size);

    for (int i; i < vec->size; i++)
    {
        printf("Data[%d]: %.2f\n", i, vec->data[i]);
    }
}

int size(const FloatVector *vec)
{
    return vec->size;
}