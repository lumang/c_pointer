#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int id;
    char name[20];
    int age;
}Person;

/**
 * @brief 线性查找
 * @param p 数据
 * @param n 数据个数
 * @param name 查找的姓名
 * @param foundCount 输出参数，匹配结果数量
 * @return 匹配结果数组指针（需调用者free）
 */
Person* searchByName(Person* p, int n, const char* name, int age, int* foundCount) 
{
    *foundCount = 0;
    if(!p || n <= 0 || !name) return NULL;

    // 第一次遍历：统计匹配数量
    int count = 0;
    for(int i = 0; i < n; i++) {
        if((strstr(p[i].name, name) != NULL)&& (p[i].age < age)) { // 精确匹配
            count++;
        }
    }
    if(count == 0) return NULL;

    // 精确分配所需内存
    Person* result = (Person*)malloc(sizeof(Person) * count);//函数释放后，指针指向的内存空间可用
    if(!result) return NULL;

    // 第二次遍历：填充结果
    int index = 0;
    for(int i = 0; i < n; i++) {
        if((strstr(p[i].name, name) != NULL)&& (p[i].age<age)) {
            result[index++] = p[i]; // 结构体复制
        }
    }

    *foundCount = count;
    return result;
}
int main()
{
    Person p[] = {
        {1, "Tom", 20},
        {2, "Jerry", 18},
        {3, "Alice", 22},
        {4, "Bob", 19},
        {5, "错误的内容", 29},
        {6, "错误的内容", 19},
    };
   
    int matchCount;
    Person* results = searchByName(p, sizeof(p)/sizeof(p[0]), "错误",20,&matchCount);

    if(results) {
        for(int i = 0; i < matchCount; i++) {
            printf("Found: %d \n", results[i].id);
            
        printf("%d %s %d\n", results[i].id, results[i].name, results[i].age);
    }
        free(results); // 必须释放内存！
    }
    return 0;
}