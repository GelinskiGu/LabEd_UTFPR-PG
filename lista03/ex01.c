#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char nome[64];
    int idade;
} Pessoa;

Pessoa *aloca();
void leitura(FILE *arquivo, Pessoa *pointer);
int iguais(Pessoa *pA, Pessoa *pB, int i);

void main()
{
    Pessoa *pPessoasA = NULL, *pPessoasB = NULL;
    int op, op2;
    pPessoasA = aloca();
    pPessoasB = aloca();
    FILE *arqA, *arqB;
    arqA = fopen("PessoaA.txt", "r");
    arqB = fopen("PessoaB.txt", "r");
    if (arqA == NULL || arqB == NULL)
        printf("Erro na abertura do arquivo.\n");
    leitura(arqA, pPessoasA);
    leitura(arqB, pPessoasB);

    while (op)
    {
        int igual;
        printf("Deseja ver se sao pessoas iguais?\n");
        printf("1 - Sim\n2 - Nao\n");
        scanf("%d", &op);
        printf("Quais pessoas deseja saber se sao iguais?");
        scanf("%d", &op2);
        igual = iguais(pPessoasA, pPessoasB, op2);
        if (igual != 0)
            printf("Pessoas diferentes.\n");
        else
            printf("Pessoas iguais.\n");
    }
}

Pessoa *aloca()
{
    Pessoa *pAloca = NULL;
    pAloca = (Pessoa *)malloc(sizeof(Pessoa) * 4);
    if (pAloca == NULL)
        return NULL;
    return pAloca;
}

void leitura(FILE *arquivo, Pessoa *pointer)
{
    if (arquivo == NULL || pointer == NULL)
        printf("Erro");
    for (int i = 0; i < 4; i++)
        fscanf(arquivo, "%s %d", &((pointer + i)->nome), &((pointer + i)->idade));
}

int iguais(Pessoa *pA, Pessoa *pB, int i)
{
    int igual;
    igual = strcmp((pA + i - 1)->nome, (pB + i - 1)->nome);
    return igual;
}