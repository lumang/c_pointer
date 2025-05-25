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
# [结构体](https://www.tutorialspoint.com/cprogramming/c_structures.htm)
参考[C Structures](https://www.tutorialspoint.com/cprogramming/c_structures.htm)
结构体是一种数据类型，它可以组合多个变量，并定义变量的顺序。
## 1 定义结构体
```c
struct student {
    char name[20];
    int age;
    float score;
};
```
## 2 访问结构体成员
```c
struct student stu;
stu.age = 18;
stu.score = 90.5;
strcpy(stu.name, "Tom");
```
## 3 结构体指针
```c
struct student stu;
struct student *p = &stu;
p->age = 18;
p->score = 90.5;
strcpy(p->name, "Tom");
```
## 4 结构体数组
```c
struct student stu[3];
stu[0].age = 18;
stu[0].score = 90.5;
strcpy(stu[0].name, "Tom");
```
## 5 结构体指针数组
```c
struct student stu[3];
struct student *p[3];
p[0] = &stu[0];
p[0]->age = 18;
p[0]->score = 90.5;
strcpy(p[0]->name, "Tom");
```
## 6 结构体嵌套
```c
struct student {
    char name[20]; // 学生的姓名
    int age; // 学生的年龄
    float score; // 学生的成绩
    struct address {
        char city[20]; // 学生所在的城市
        char street[20]; // 学生所在的街道
        int number; // 学生所在的门牌号
    } addr; // 学生的地址
};
```
   
# 回调函数
基础 函数指针
参考[callback](https://www.geeksforgeeks.org/callbacks-in-c/)
```c
#include <stdio.h>

// Callback function to compare two numbers
int comp(int a, int b) {
    if (a > b) return a;
    return b;
}

// Function that accepts a callback for comparison
void Max(int (*callback)(int, int), int x, int y) {
  
    // Calls the callback function
    int res = callback(x, y);  
    printf("%d", res);
}

int main() {
    int x = 7, y = 10;

    // Pass the compareNumbers function as callback
    Max(comp, x, y);

    return 0;
}
```
# 多文件编译
> gcc main.c file1.c file2.c -o output
