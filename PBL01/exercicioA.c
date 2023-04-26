#include <stdio.h>

int main()
{
    int a1, n, r, an;
    printf("Informe o A1: ");
    scanf("%d",&a1);
    printf("Informe o r: ");
    scanf("%d",&r);
    printf("Informe o n: ");
    scanf("%d",&n);
    an=a1+(n-1)*r;
    printf("O valor de A%d é igual a %d\n",n,an);
    return(0);
}