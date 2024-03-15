typedef struct aluno{
    int matricula;
    float n1,n2,n3;
}ALUNO;

typedef struct elemento* Lista;

Lista *criaLista();

int insere_inicio_lista(Lista *li, ALUNO al);

int insere_lista_ordenada(Lista *li, ALUNO al);

int insere_final_lista(Lista *li, ALUNO al);

int consulta_lista_pos(Lista *li, int posicao, ALUNO *al);

int consulta_lista_mat(Lista *li, int matricula, ALUNO *al);

int listaCheia(Lista *li);

int remove_inicio_lista(Lista *li);

int remove_lista(Lista *li, int mat);

int remove_final_lista(Lista *li);

int tamLista(Lista *li);

int listaVazia(Lista *li);

void apagaLista(Lista *li);

void coletadados(ALUNO *al);

void imprimeAluno(ALUNO al);
