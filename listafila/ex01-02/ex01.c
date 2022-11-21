#include <stdlib.h>
#include <stdio.h>
// Teste
typedef struct Pessoa
{
    int idade;
    struct Pessoa *prox;
} TPessoa;

typedef struct Controle
{
    TPessoa *inicio;
    TPessoa *fim;
} TNo;

void insereFim(TNo *cabeca1, TNo *cabeca2, int k);
TNo *inicializa();
TPessoa *alocaPessoa(int k);
void insereFim(TNo *cabeca1, TNo *cabeca2, int k);
void imprimeLista(TPessoa *p1, TPessoa *p2, TNo *c1, TNo *c2);
void removeInicio(TNo *p);
void atendimento(TNo *p1, TNo *p2, int k);

int main()
{
    TNo *cabeca60 = inicializa();
    TNo *cabeca = inicializa();
    int k = 1;
    while (k)
    {
        scanf("%d", &k);
        insereFim(cabeca60, cabeca, k);
    }
    imprimeLista(cabeca60->inicio, cabeca->inicio, cabeca60, cabeca);
    scanf("%d", &k);
    atendimento(cabeca60, cabeca, k);
    imprimeLista(cabeca60->inicio, cabeca->inicio, cabeca60, cabeca);
}

TNo *inicializa()
{
    TNo *novo = NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if (!novo)
        return NULL;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

TPessoa *alocaPessoa(int k)
{
    TPessoa *novo = NULL;
    novo = (TPessoa *)malloc(sizeof(TPessoa));
    if (!novo)
        return NULL;
    novo->idade = k;
    novo->prox = NULL;
    return novo;
}

void insereFim(TNo *cabeca1, TNo *cabeca2, int k)
{
    TPessoa *novo = NULL;
    novo = alocaPessoa(k);
    if (!k)
        return;
    if (k > 60)
    {
        if (!(cabeca1->inicio))
        {
            cabeca1->inicio = novo;
            cabeca1->fim = novo;
        }
        else
        {
            cabeca1->fim->prox = novo;
            cabeca1->fim = novo;
        }
    }
    else
    {
        if (!(cabeca2->inicio))
        {
            cabeca2->inicio = novo;
            cabeca2->fim = novo;
        }
        else
        {
            cabeca2->fim->prox = novo;
            cabeca2->fim = novo;
        }
    }
}

void imprimeLista(TPessoa *p1, TPessoa *p2, TNo *c1, TNo *c2)
{
    int cont;
    if (p1)
    {
        for (cont = 0; p1; cont++)
            p1 = p1->prox;
        printf("%d %d %d\n", cont, c1->fim->idade, c1->inicio->idade);
    }
    else
        printf("0 0 0\n");

    if (p2)
    {
        for (cont = 0; p2; cont++)
            p2 = p2->prox;
        printf("%d %d %d\n", cont, c2->fim->idade, c2->inicio->idade);
    }
    else
        printf("0 0 0\n");
    ;
}

void removeInicio(TNo *p)
{
    TPessoa *aux = NULL;
    if (p->inicio)
    {
        aux = p->inicio;
        p->inicio = aux->prox;
        free(aux);
        aux = NULL;
    }
}

void atendimento(TNo *p1, TNo *p2, int k)
{
    if (p1 && p2)
    {
        while (k)
        {
            if (p1->inicio)
            {
                removeInicio(p1);
                k--;
            }
            else if (p2->inicio)
            {
                removeInicio(p2);
                k--;
            }
            else
                break;
        }
    }
}