typedef struct vizinho 
{
	int idVizinho;
	struct vizinho* prox;
} Vizinho;

typedef struct grafo 
{
	int idVertice;
	Vizinho* primeiroVizinho;
	struct grafo* prox;
} Grafo;

void inicializa(Grafo** g);
Grafo* preencheVertices(Grafo* g);
void imprimeGrafo(Grafo* g);
void libera(Grafo* g);
void liberaVizinhos(Vizinho* v);
int numeroDeArestas (Grafo* g);
int numeroDeVertices(Grafo* g);
bool testek(Grafo* g, int k);
bool GrafosIguais(Grafo* g1, Grafo* g2);
