#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gustavo Gelinski RA: 2466635
// Lucas Alves Pereira RA: 2422670

typedef struct Pessoa
{
    char nome[15];
    int idade, dose1, dose2; // considere valor 1 para vacinado e 0 não vacinado
    char vacina[10];         // nome da vacina que tomou na 1ª dose
    struct Pessoa *pprox;
} TPessoa;

// int lerArquivoY(FILE *parquivo); Essa funcao iria servir para contar a quantidade de linhas que tem no .dat, porem nao foi necessario usar ela.
void imprimeLista(TPessoa *p);
TPessoa *alocaNo(FILE *parquivo);
void insereFimListaSimples(TPessoa **primY, FILE *parquivo);
void unifica(TPessoa *p1, TPessoa *p2);
void insereFimListaUnificada(TPessoa *paux1, TPessoa *paux2, TPessoa *pX);
void buscaPessoa(TPessoa *primX, char nome[15]);
void insereFinalListaSemDoses(TPessoa *primX, char nome[15]);
void desalocarListas(TPessoa **prim);
void armazenar(FILE *parquivo, TPessoa *pX);

int main()
{
    FILE *p1, *p2, *p3;
    TPessoa *pY = NULL, *pZ = NULL, *pX = NULL;
    int op = 1, op3;
    p1 = fopen("postoY.dat", "r");
    p2 = fopen("postoZ.dat", "r");
    pY = alocaNo(p1);
    pZ = alocaNo(p2);
    pX = alocaNo(p2);
    while (!(feof(p1)))
        insereFimListaSimples(&pY, p1);
    while (!(feof(p2)))
        insereFimListaSimples(&pZ, p2);
    while (op != 5)
    {
        printf("\n1 - Unificar arquivos de dados - Pessoas\n2 - Busca pessoa - Vacinar\n3 - Imprimir informacoes das pessoas\n4 - Desalocar todas as pessoas\n5 - Sair\n\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            if (pY != NULL & pZ != NULL)
            {
                if (!pX->pprox)
                {
                    unifica(pY, pX);
                    unifica(pZ, pX);
                }
                else
                    printf("Voce ja unificou os arquivos.\n");
            }
            else
                printf("Os postos estao desalocados, portanto nao é possivel unificar os arquivos.\n");
        }
        break;
        case 2:
        {
            fflush(stdin);
            char nome[15];
            printf("Insira o nome de quem voce deseja buscar.\n");
            scanf("%s", nome);
            fflush(stdin);
            if (pX)
                buscaPessoa(pX, nome);
            else
                printf("Os postos foram desalocados, portanto nao é possivel buscar uma pessoa.\n");
        }
        break;
        case 3:
        {
            int op2;
            printf("Qual posto deseja ver as informacoes?\n1 - Pessoas Posto Y\n2 - Pessoas Posto Z\n3 - Pessoas Posto X(unificado)\n");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                imprimeLista(pY);
                break;
            case 2:
                imprimeLista(pZ);
                break;
            case 3:
                if (pX)
                    if (pX->pprox)
                        imprimeLista(pX);
                    else
                        printf("É necessário unificar os arquivos antes.\n");
                else
                    printf("Posto X ja foi desalocado.\n");
                break;
            default:
                break;
            }
        }
        break;
        case 4:
        {
            if (pY)
                while (pY)
                    desalocarListas(&pY);
            if (pZ)
                while (pZ)
                    desalocarListas(&pZ);
            if (pX)
                if (pX->pprox)
                {
                    while (pX)
                        desalocarListas(&pX);
                }
            if (!pY)
                printf("Posto Y desalocado!\n");
            if (!pZ)
                printf("Posto Z desalocado!\n");
            if (!pX)
                printf("Posto X desalocado!\n");
        }
        break;
        case 5:
        {
            if (pX)
                if (pX->pprox)
                {
                    p3 = fopen("unificadoZY.dat", "w");
                    armazenar(p3, pX);
                    desalocarListas(&pY);
                    desalocarListas(&pZ);
                    desalocarListas(&pX);
                }
                else
                {
                    printf("Informacoes do posto X indisponiveis.\n");
                    if (pY)
                        while (pY)
                            desalocarListas(&pY);
                    if (pZ)
                        while (pZ)
                            desalocarListas(&pZ);
                    if (pX)
                        while (pX)
                            desalocarListas(&pX);
                }
            else
                printf("O posto X ja foi desalocado anteriormente.\n");
        }
        break;
        default:
            printf("Insira um numero de 1 a 5.\n");
        }
    }

    fclose(p1);
    fclose(p2);
    if (p3)
        fclose(p3);
}

TPessoa *alocaNo(FILE *parquivo)
{
    TPessoa *novo = NULL;
    novo = (TPessoa *)malloc(sizeof(TPessoa));
    if (novo)
        fscanf(parquivo, "%s %d %d %d %s\n", novo->nome, &novo->idade, &novo->dose1, &novo->dose2, novo->vacina);
    else
    {
        return NULL;
    }
    novo->pprox = NULL;
    return (novo);
}

void insereFimListaSimples(TPessoa **primY, FILE *parquivo)
{
    TPessoa *aux = NULL, *aux2 = *primY;
    aux = alocaNo(parquivo);
    if (!aux)
        return;
    if (!(*primY))
    {
        aux->pprox = *primY;
        *primY = aux;
        return;
    }
    else
    {
        while (aux2->pprox)
            aux2 = aux2->pprox;
        aux2->pprox = aux;
    }
}

void imprimeLista(TPessoa *p)
{
    if (p)
    {
        while (p)
        {
            printf("%s %d %d %d %s\n", p->nome, p->idade, p->dose1, p->dose2, p->vacina);
            p = p->pprox;
        }
    }
    else
    {
        printf("\nPosto vazio!\n");
    }
}

void unifica(TPessoa *p1, TPessoa *p2)
{
    TPessoa *aux1 = NULL, *aux2 = NULL;
    aux1 = p1;
    aux2 = p2;
    int temp, retorno;
    while (aux1->pprox)
    {
        temp = 0;

        aux2 = p2;
        while (aux2->pprox)
        {
            retorno = strcmp(aux2->nome, aux1->nome);
            if (!retorno)
            {
                if (aux1->dose2 == 1)
                    aux2->dose2 = 1;
                temp = 1;
            }
            aux2 = aux2->pprox;
        }
        if (!temp)
            insereFimListaUnificada(aux1, aux2, p2);
        aux1 = aux1->pprox;
    }
    insereFimListaUnificada(aux1, aux2, p2);
}
void insereFimListaUnificada(TPessoa *paux1, TPessoa *paux2, TPessoa *pX)
{
    TPessoa *aux = NULL, *pessoa = NULL;
    pessoa = (TPessoa *)malloc(sizeof(TPessoa));
    if (pessoa)
    {
        strcpy(pessoa->nome, paux1->nome);
        pessoa->idade = paux1->idade;
        pessoa->dose1 = paux1->dose1;
        pessoa->dose2 = paux1->dose2;
        strcpy(pessoa->vacina, paux1->vacina);
        pessoa->pprox = NULL;
    }
    aux = pX;
    while (aux->pprox)
        aux = aux->pprox;
    aux->pprox = pessoa;
}

void buscaPessoa(TPessoa *primX, char nome[15])
{
    if (primX->pprox == NULL)
    {
        printf("Os postos ainda não foram unificados. Favor unificar antes de buscar alguma pessoa.\n");
        return;
    }
    TPessoa *aux = NULL;
    aux = primX;
    int retorno;
    int temp = 0, temp2 = 0;
    while (aux->pprox)
    {
        retorno = strcmp(nome, aux->nome);
        if (!retorno) // Caso as strings sejam iguais elas entram no if
        {
            temp = 1;        // Caso esse valor seja igual a 1 significa que nao é necessario colocar esse nome na lista para nao ter nomes repetidos.
            temp2 = 1;       // Para nao fazer essas condicionais 2 vezes quando sair do while esse temp2 é necessario
            if (!aux->dose1) // Condicao para dose1. Quando se cria uma nova pessoa ela vem com dose1 == 0
            {
                int op2;
                printf("%s ainda não tomou sua primeira dose!\nDeseja se vacinar?\n1-Sim\n2-Nao\n", nome);
                scanf("%d", &op2);
                if (op2 == 1)
                {
                    op2 = 0;
                    printf("Qual vacina?\n1-Pfizer\n2-Coronavac\n");
                    scanf("%d", &op2);
                    if (op2 == 1)
                    {
                        aux->dose1 = 1;
                        strcpy(aux->vacina, "pfizer");
                        printf("1° dose da Pfizer aplicada com sucesso!\n");
                        break;
                    }
                    else
                    {
                        aux->dose1 = 1;
                        strcpy(aux->vacina, "coronavac");
                        printf("1° dose da Coronavac aplicada com sucesso!\n");
                    }
                }
                break;
            }
            if (!aux->dose2)
            {
                int op;
                printf("%s precisa tomar a 2° dose da %s.\n", nome, aux->vacina);
                printf("Voce deseja tomar a 2° dose da %s?\n1-Sim\n2-Nao\n", aux->vacina);
                scanf("%d", &op);
                if (op == 1)
                {
                    aux->dose2 = 1;
                    printf("%s tomou sua 2° dose com sucesso!\n", nome);
                    break;
                }
                else
                {
                    printf("2° dose não realizada.\n");
                    break;
                }
            }
            printf("%s já tomou suas 2 doses de vacina!\n", nome);
            break;
        }
        aux = aux->pprox;
    }
    retorno = strcmp(nome, aux->nome);
    if (!retorno & !temp2) // Como o ultimo nome da lista nao passa pelo primeiro strcmp é necessario fazer as condicionais para o ultimo nome fora do while.
    {
        temp = 1;
        if (!aux->dose1)
        {
            int op2;
            printf("%s ainda não tomou sua primeira dose!\nDeseja se vacinar?\n1-Sim\n2-Nao\n", nome);
            scanf("%d", &op2);
            if (op2 == 1)
            {
                op2 = 0;
                printf("Qual vacina?\n1-Pfizer\n2-Coronavac\n");
                scanf("%d", &op2);
                if (op2 == 1)
                {
                    aux->dose1 = 1;
                    strcpy(aux->vacina, "pfizer");
                    printf("1° dose da Pfizer aplicada com sucesso!\n");
                    return;
                }
                else
                {
                    aux->dose1 = 1;
                    strcpy(aux->vacina, "coronavac");
                    printf("1° dose da Coronavac aplicada com sucesso!\n");
                }
            }
            return;
        }
        if (!aux->dose2)
        {
            int op;
            printf("%s precisa tomar a 2° dose da %s.\n", nome, aux->vacina);
            printf("Voce deseja tomar a 2° dose da %s?\n1-Sim\n2-Nao\n", aux->vacina);
            scanf("%d", &op);
            if (op == 1)
            {
                aux->dose2 = 1;
                printf("%s tomou sua 2° dose com sucesso!\n", nome);
                return;
            }
            else
            {
                printf("2° dose não realizada.\n");
                return;
            }
        }
        printf("%s já tomou suas 2 doses de vacina!\n", nome);
        return;
    }
    if (!temp)
        insereFinalListaSemDoses(primX, nome);
}

void insereFinalListaSemDoses(TPessoa *primX, char nome[15]) // Procedimento para inserir alguem na lista quando se está fazendo a busca/vacinar e a pessoa nao esta na lista.
{
    TPessoa *aux = NULL;
    TPessoa *novo = NULL;
    int idade;
    char vacina[15] = "Nenhuma";
    printf("%s não está registrado no sistema.\n", nome);
    printf("Qual é a idade de %s?\n", nome);
    scanf("%d", &idade);
    novo = (TPessoa *)malloc(sizeof(TPessoa));
    if (novo)
    {
        strcpy(novo->nome, nome);
        novo->idade = idade;
        novo->dose1 = 0;
        novo->dose2 = 0;
        strcpy(novo->vacina, "nenhuma");
        aux = primX;
        while (aux->pprox)
        {
            aux = aux->pprox;
        }
        aux->pprox = novo;
    }
    printf("%s registrado com sucesso! Caso queira tomar alguma dose favor pressionar 2 novamente.\n", nome);
}
/*
int lerArquivoY(FILE *parquivo)
{
    TPessoa *temp = NULL;
    temp = (TPessoa *)malloc(sizeof(TPessoa));
    char nome[15];
    char vacina[10];
    int idade, dose1, dose2;
    int cont = 0;
    while (!feof(parquivo))
    {
        fscanf(parquivo, "%s %d %d %d %s\n", temp->nome, &temp->idade, &temp->dose1, &temp->dose2, temp->vacina);
        cont++;
    }
    free(temp);
    temp = NULL;
    return cont;
}
*/

void desalocarListas(TPessoa **prim)
{
    if (*prim == NULL)
        return;
    TPessoa *aux = NULL;
    aux = *prim;
    *prim = (*prim)->pprox;
    free(aux);
    *prim = NULL;
}

void armazenar(FILE *parquivo, TPessoa *pX)
{
    TPessoa *aux = NULL;
    aux = pX;
    while (aux->pprox)
    {
        fprintf(parquivo, "%s %d %d %d %s\n", aux->nome, aux->idade, aux->dose1, aux->dose2, aux->vacina);
        aux = aux->pprox;
    }
    fprintf(parquivo, "%s %d %d %d %s\n", aux->nome, aux->idade, aux->dose1, aux->dose2, aux->vacina);
}