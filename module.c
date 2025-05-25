#include<stdio.h>
#include<string.h>
#include"student_op.h"
#if 1 // v2.0 使用模块化
void add_student(Student *s,int* studentCount,Student newStudent)
{
    s[*studentCount] = newStudent;
    (*studentCount)++;
}
void search_student(Student *s,int studentCount,char *name)
{
    int found = 0;
    for(int i = 0; i < studentCount; i++)
     {
        //if(strcmp(s[i].name, name) ==0) // strcmp函数用于比较两个字符串是否相等，如果相等返回0
        if(strstr(s[i].name, name) !=NULL) // strcmp函数用于比较两个字符串是否相等，如果相等返回0
        {
            printf("找到学生：姓名 %s,年龄 %d,成绩 %.2f\n", s[i].name, s[i].age, s[i].score);
            found =1;
            break;
        }
        if(!found)
        {
            printf("未找到该学生\n");
        }
     }

}
void display_all_students(Student *s,int studentCount)
{
    printf("所有学生信息如下：\n");
    for(int i =0; i < studentCount; i++) 
    {
        printf("姓名 %s,年龄 %d,成绩 %.2f\n", s[i].name, s[i].age, s[i].score);
    }
}

int main()
{ 
    Student s[100];
    int studentCount = 0;
    Student newStudent;
    printf("请输入学生姓名：");
    scanf("%s", newStudent.name);
    printf("请输入学生年龄：");
    scanf("%d", &newStudent.age);
    printf("请输入学生成绩：");
    scanf("%f", &newStudent.score);
    add_student(s,&studentCount,newStudent);
    char searchName[50];
    printf("请输入要查询的学生姓名：");
    scanf("%s", searchName);
    search_student(s,studentCount,searchName);
    display_all_students(s,studentCount);
    return 0;
}
#endif 

#if 0 // v1.0 未使用模块化

// 定义学生结构体
typedef struct 
{ 
    char name[50];
    int age;
    float score;
} Student;
int main()
{
    Student students[100];
    int studentCount = 0;
// 添加学生信息功能    
     Student newStudent;
     printf("请输入学生姓名：");
     scanf("%s", newStudent.name);
     printf("请输入学生年龄：");
     scanf("%d", &newStudent.age);
     printf("请输入学生成绩：");
     scanf("%f", &newStudent.score);
     students[studentCount] = newStudent;
     studentCount++;
    //查询学生信息功能    
    char searchName[50];
    printf("请输入要查询的学生姓名：");
    scanf("%s", searchName);
    int found = 0;
    for(int i = 0; i < studentCount; i++)
     {
        //if(strcmp(students[i].name, searchName) ==0) // strcmp函数用于比较两个字符串是否相等，如果相等返回0
        if(strstr(students[i].name, searchName) !=NULL) // strstr函数用于查找子字符串在字符串中首次出现的位置，如果找到返回指向该位置的指针，否则返回NULL,用来模糊搜索
        {
            printf("找到学生：姓名 %s,年龄 %d,成绩 %.2f\n", students[i].name, students[i].age, students[i].score);
            found =1;
            break;
        }
    }
    if(!found)
     {
        printf("未找到该学生\n");
     }
//显示所有学生信息功能    
    printf("所有学生信息如下：\n");
    for(int i =0; i < studentCount; i++) 
    {
        printf("姓名 %s,年龄 %d,成绩 %.2f\n", students[i].name, students[i].age, students[i].score);
    }
    return 0;
}
#endif