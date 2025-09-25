#define TAM_DADOS_PILHA 10

typedef struct pilhas pilhas;

pilhas* criaPilha (void);
void push (pilhas *pilha, int dado);
void pop (pilhas *pilha);
void topo(pilhas *pilha);
void imprimeLista(pilhas *pilha);