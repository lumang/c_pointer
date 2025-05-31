#include<stdio.h>

int main(void)
{
    int i, j, n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)// 乘法表
    {
        for(j=1; j<=i; j++)
        {
            printf("%d*%d=%d\t",i,j, i*j);
        }
        printf("\n");
    }
    return 0;
}