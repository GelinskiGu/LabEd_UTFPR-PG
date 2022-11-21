#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10

typedef struct
{
    int vetor[tam];
    int n;
} Lista;

Lista *aloca();
void inicia(Lista *p);
void adicionar(Lista *p);
void imprimir(Lista *p);
int nElementos(Lista *p);

void main()
{
    Lista *pLista = NULL;
    int op = 1;
    pLista = aloca();
    inicia(pLista);

    while (op)
    {
        printf("O que deseja fazer?\n");
        printf("1 - Adicionar;\n2 - Quantidade de elementos;\n3 - Remover;\n4 - Imprimir;\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            adicionar(pLista);
            break;
        case 2:
        {
            int qtde = nElementos(pLista);
            printf("O numero de elementos guardados e: %d\n", qtde);
        }
        break;
        case 3:
            // remover(pLista);
            break;
        case 4:
            imprimir(pLista);
            break;
        }
    }
}

Lista *aloca()
{
    Lista *p = NULL;
    p = (Lista *)malloc(sizeof(Lista));
    if (p == NULL)
    {
        printf("Memoria insuficiente.\n");
        return NULL;
    }
    return p;
}

void inicia(Lista *p)
{
    if (p == NULL)
    {
        printf("Memoria insuficiente.\n");
    }
    for (int i = 0; i <= tam; i++)
        p->vetor[i] = 0;
}

void adicionar(Lista *p)
{
    int elemento;
    if (p == NULL)
    {
        printf("Nao existe lista!\n");
    }
    printf("Qual elemento deseja adicionar?\n");
    scanf("%d", &elemento);
    for (int i = 0; i < tam; i++)
    {
        if ((p->vetor[i]) == 0)
        {
            (p->vetor[i]) = elemento;
            i = tam;
        }
        if ((p->vetor[tam - 1]) != 0 && i == (tam - 1))
        {
            printf("Erro: lista cheia.\n");
        }
    }
}

void imprimir(Lista *p)
{
    if (p == NULL)
    {
        printf("Erro.\n");
    }
    printf("[");
    for (int i = 0; i < tam - 1; i++)
    {
        printf("%d; ", p->vetor[i]);
    }
    printf("%d]\n", p->vetor[tam - 1]);
}

int nElementos(Lista *p)
{
    if (p == NULL)
    {
        printf("Nao existe a lista.\n");
    }
    int cont = 0;
    for (int i = 0; i < tam; i++)
        if (p->vetor[i] != 0)
            cont++;

    return cont;
}