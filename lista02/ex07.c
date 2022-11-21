#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void soma(int **pa, int **pb);

void main()
{
    int a, b, *pa = NULL, *pb = NULL;
    scanf("%d%d", &a, &b);
    pa = &a;
    pb = &b;

    soma(&pa, &pb);
    printf("%d %d\n", a, b);
}

void soma(int **pa, int **pb)
{
    **pa += **pb;
}