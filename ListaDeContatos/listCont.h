
// Defini��o da estrutura Cliente
typedef struct {
    int codigo;
    char nome[50];
    char empresa[50];
    char departamento[50];
    char telefone[15];
    char celular[15];
    char email[50];
} Cliente;

// Defini��o da estrutura Elem
typedef struct elemento Elem;

// Defini��o do tipo Lista como um ponteiro para Elem
typedef Elem* Lista;

// Prot�tipos das fun��es
Lista* criaLista();
void liberaLista(Lista* li);
void salvaLista(Lista* li);
void insereOrdenado(Lista* li, Cliente c);
void exibeLista(Lista* li);
void buscaPorCodigo(Lista* li, int codigo);
void buscaPorNome(Lista* li, const char* nome);
void editaCliente(Lista* li, int codigo);
void removeCliente(Lista* li, int codigo);
void carregaLista(Lista* li);
