#include<stdio.h>

int main()
{
    float a = 3.14,b;
    printf("输入两个实数字: ");
    scanf("%f %f",&a,&b);
    printf("较大是是 %.2f\n",a>b?a:b);//格式化输出，保留两位小数
}