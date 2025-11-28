// AVIÃO
typedef struct
{
	char tarefa[30];
	int prior;
} dados;

dados* novaTarefa(int numTarefas);
int* geraPrioridades(int numTarefas);
dados* incrementarTarefas(dados* tarefas, int *novoTamanho);
