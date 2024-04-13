#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> 

typedef struct {
  int *numbers;
  //int size;              // how many numbers should store
  int capacity;          // size of a collection
} Stack;

void create_stack (int capacity1, int capacity2, Stack **stack_p1, Stack **stack_p2);
//bool is_full (Stack *stack);
//bool is_empty (Stack *stack);
void push (Stack **stack_p1, Stack **stack_p2);
void print_stack (Stack **stack_p1, Stack **stack_p2);
void pop (Stack **stack_p1, Stack **stack_p2);
void stack_compare (Stack **stack_p1, Stack **stack_p2);
//void destroy_stack (Stack *stack);

int main () {
    int capacity1, capacity2, opc = 0;
    Stack *stack_p1, *stack_p2;

    printf ("Insira a capacidade da Stack P1: ");
    scanf ("%d", &capacity1);

    printf ("Insira a capacidade da Stack P2: ");
    scanf ("%d", &capacity2);

    create_stack (capacity1, capacity2, &stack_p1, &stack_p2);
  
    do {
        printf ("======== Stack Menu ========\n");
        printf ("[1] Empilhar \n[2] Desempilhar \n[3] Imprimir. \n[4] Comparar \n[0] Exit\n\n");
        printf ("Escolha uma opção: ");
        scanf ("%d", &opc);
        switch (opc)
        {
        case 1: 
            push (&stack_p1, &stack_p2);
            break;
        case 2:
            pop (&stack_p1, &stack_p2);
            break;
        case 3:
            print_stack (&stack_p1, &stack_p2);
            break;
        case 4:
            stack_compare (&stack_p1, &stack_p2);
            break;
        case 0:
            break;
        default:
            printf("\nOpção inválida. Tente novamente.\n\n");
            break;
        }
    } while (opc != 0);
}

void create_stack (int capacity1, int capacity2, Stack **stack_p1, Stack **stack_p2) {

    if (capacity1 <= 0 || capacity2 <= 0) {
        printf("Impossível criar uma pilha menor ou igual a zero.\n");
        exit (0);
  }
    
    *stack_p1 = malloc (sizeof(Stack));
    if (stack_p1 == NULL) {
        printf ("Erro ao alocar espaço para a pilha 1"); 
        exit (0);
    }

    *stack_p2 = malloc (sizeof(Stack));
    if (stack_p2 == NULL) {
        printf ("Erro ao alocar espaço para a pilha 2"); 
        exit (0);
    }

    (*stack_p1)->numbers = malloc (sizeof(int) * capacity1);
    if (stack_p1 == NULL) {
        printf ("Erro ao alocar espaço para a pilha 1"); 
        exit (0);
    }

    (*stack_p2)->numbers = malloc (sizeof(int) * capacity2);
    if (stack_p1 == NULL) {
        printf ("Erro ao alocar espaço para a pilha 1"); 
        exit (0);
    }

    (*stack_p1)->capacity = capacity1;
    (*stack_p2)->capacity = capacity2;
}

void push (Stack **stack_p1, Stack **stack_p2) {

    for (int i = 0; i < (*stack_p1)->capacity; i++) {
        printf ("[Pilha 1] Insira o item %d: ", i+1);
        scanf ("%d", &(*stack_p1)->numbers[i]);
    }

    printf ("\n");

    for (int i = 0; i < (*stack_p2)->capacity; i++) {
        printf ("[Pilha 2] Insira o item %d: ", i+1);
        scanf ("%d", &(*stack_p2)->numbers[i]);
    }
}

void print_stack (Stack **stack_p1, Stack **stack_p2) {

        for (int i = 0; i < (*stack_p1)->capacity; i++) {
        printf ("[Pilha 1] Item %d = %d\n", i, (*stack_p1)->numbers[i]);
    }

    printf("\n");

    for (int i = 0; i < (*stack_p2)->capacity; i++) {
        printf ("[Pilha 2] Item %d = %d\n", i, (*stack_p2)->numbers[i]);
    }
}

void pop (Stack **stack_p1, Stack **stack_p2) {
    
    int opc = 0;
    
    do {
        printf ("Qual das pilhas deseja desempilhar?\n");
        printf ("[1] Pilha 1, [2] Pilha 2 ou [0] Retornar?: ");
        scanf ("%d", &opc);

        switch (opc)
        {
        case 1:
            (*stack_p1)->capacity--;
            break;
        case 2:
            (*stack_p2)->capacity--;
            break;
        default:
            printf("\n");
        }
    } while (opc != 0);
}

void stack_compare (Stack **stack_p1, Stack **stack_p2) {
    
    
    if ((*stack_p1)->capacity > (*stack_p2)->capacity) {
        printf ("A pilha 1 é maior que a pilha 2.\n\n");
    }
    else if ((*stack_p1)->capacity < (*stack_p2)->capacity) {
        printf ("A pilha 2 é maior que a pilha 1.\n\n");
    }
    else {
        printf ("As pilhas são iguais.\n\n");
    }
}