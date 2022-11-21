#include <stdio.h>
#include <stdlib.h>

void ordene(int **p1, int **p2, int **p3);

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    scanf("%i%i%i", pa, pb, pc);
    ordene(&pa, &pb, &pc);
    printf("PA = %i, ", *pa);
    printf("PB = %i, ", *pb);
    printf("PC = %i", *pc);
}

void ordene(int **p1, int **p2, int **p3)
{
    int aux;
    if (**p2 > **p1)
    {
        aux = **p1;
        **p1 = **p2;
        **p2 = aux;
    }
    if (**p3 > **p1)
    {
        aux = **p1;
        **p1 = **p3;
        **p3 = aux;
    }
    if (**p3 > **p2)
    {
        aux = **p2;
        **p2 = **p3;
        **p3 = aux;
    }
}