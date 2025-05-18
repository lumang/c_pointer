#include <stdio.h>
#include <stdlib.h>
int *func() {
    int *p = (int *)malloc(sizeof(int) * 2);//申请内存 函数结束不会释放
    p[0] = 1;
    p[1] = 2;
    return p;// 返回地址
}
int main() {
    int *p = func();
    printf("%d %d\n", p[0], p[1]);
    free(p);
    return 0;
}