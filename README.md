# c_pointer
c_pointer struct callback
# 入门
> 江协科技

[[C语言] 指针的详解与应用-理论结合实践，真正理解指针！](https://www.bilibili.com/video/BV1Mb4y1X7dz/?spm_id_from=333.1387.homepage.video_card.click&vd_source=3a269af70b5c8a1a3dd446fff1fabf6a)
# 应用
## 1 传递参数
> 指针传递大容量的参数，避免拷贝，提高性能

```c
// dest 源字符串 字节数组 
// src  字节数组 const  char * 防止修改
strcpy(char *dest,const char *src)   // 拷贝字符串
```
## 2 获取返回值 单个值或者多个值
```c
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
```
### 综合练习 文件读写
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 写文件
void write_file(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(fp, "%s", data);
    fclose(fp);
}

// 读文件
char *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file for reading.\n");
}
    char *data = (char *)malloc(1024);
    while (fgets(data, 1024, fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);
    return data;
}

int main() {
    const char *filename = "test.txt";
    const char *data = "Hello, World!";
    write_file(filename, data);
    char *read_data = read_file(filename);
    free(read_data);
    return 0;
}
```
## 3 直接访问物理地址下的数据
```c
int main() {
    int *p = (int *)0x1000;
    printf("%d\n", *p);
}
```
## 4 访问内存中的数据 将复杂格式转换为字节，方便通信
```c
#include <stdio.h>
#include <string.h>
//访问内存中的数据 将复杂格式转换为字节，方便通信
// float a = 1.23 转换为字节数组
void float2byte(float a, unsigned char *b) {
    memcpy(b, &a, sizeof(float));
}

//将字节数组转换为float
void byte2float(unsigned char *b, float *a) {
    memcpy(a, b, sizeof(float));
}

int main() {
    float a = 1.23;
    unsigned char b[4];
    float2byte(a, b);
    for (size_t i = 0; i < 4; i++)
    {
        printf("%d = 0x%02x ", b[i],b[i]);
    }
    
    float c;
    byte2float(b, &c);
    printf("%f\n", c);
    return 0;
}
``` 
