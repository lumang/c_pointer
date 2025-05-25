#ifndef STUDENT_OP_H
#define STUDENT_OP_H

#include<stdio.h>
#include<string.h>
typedef struct student
{
    int id;
    char name[20];
    int age;
    float score;
}Student;
void add_student(Student *s,int* studentCount,Student newStudent); //添加学生信息
void search_student(Student *s,int studentCount,char *name);
void show_students(Student *s,int studentCount);
void delete_student(Student *s,int* studentCount,int studentId); //删除学生信息
void modify_student(Student *s,int studentId,float newScore); //修改学生信息

#endif