#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *numbers;
  int size;              // how many numbers should store
  int capacity;          // size of a collection
} Stack;

Stack *create_stack (int capacity);
bool is_full (Stack *stack);
bool is_empty (Stack *stack);
void push (Stack *stack);
void pop (Stack *stack);
void destroy_stack (Stack *stack);

int main () {
  int capacity;
  
  printf ("Insira quantos números deseja guardar na pilha: ");
  scanf ("%d", &capacity);
    
  Stack *stack = create_stack(capacity);
  Stack *stackP2 = create_stack(capacity);

  printf ("Tamanho da stack: %d.\n", stack->size);                         // verifica tamanho da stack

  push (stack);

  for (int i = 0; i < stack->capacity; i++) {
    printf("Item [%d]: %d\n", i+1, stack->numbers[i]);
  }
    if (is_full(stack) == true) {
        printf ("A pilha está cheia.\n\n");
    }
}

Stack *create_stack (int capacity) {

  if (capacity <= 0) {
    printf("Impossível criar uma pilha menor ou igual a zero.\n");
    return NULL;
  }

  Stack *stack = malloc(sizeof(Stack));            // *stack aponta para o endereço base reservado para o tipo Stack
  if (stack == NULL) {
    printf("Erro ao construir a stack.\n");
    return NULL;
  }

  stack->numbers = malloc (sizeof(int) * capacity);

  if (stack->numbers == NULL) {
    free (stack);
    return NULL;
  }

  stack->capacity = capacity;
  stack->size = 0;
  
  return stack;
}

bool is_full (Stack *stack) {  
    return (stack->size == stack->capacity);
}

bool is_empty (Stack *stack) {
  if (stack->size == 0) {
    printf ("A pilha está vazia.\n");
    return true;
  }
  return false;
}

void push (Stack *stack) { 
  printf("Insira os números desejados.\n");

  for (int i = 0; i < stack->capacity; i++) {
    printf("Insira o %d° número: ", i+1);
    scanf("%d", &stack->numbers[i]);
    stack->size++;
  }
}