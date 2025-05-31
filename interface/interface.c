#include<stdio.h>

int main()
{
    //
    int num = 0;
    for(int i=1;i*i<200;i++)
    {

        printf("i*i = %d ",i*i);
        num++;
        if(num%5==0)
        {
            printf("\n");
        }
    }
    printf("Hello World");
}