#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<iostream>
#include "myList.h"
void menu()
{
    printf("请选择操作\n");
    printf("\t\*******************************\n");
    printf("\t\*          1 插入             *\n");
    printf("\t\*          2 查找             *\n");
    printf("\t\*          3 删除             *\n");
    printf("\t\*          4 修改             *\n");
    printf("\t\*          5 输出             *\n");
    printf("\t\*          6 退出             *\n");
    printf("\t\*******************************\n");

}
struct Node* list = createList();
void keyDown()
{
    int choice = 0;
    struct student data;
    struct Node* pMove=NULL;
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("***********插入信息***********\n");
        printf("请输入学生学号，姓名，出生年月，性别：");
        fflush(stdin);
        scanf("%d%s%s%d",data.ID,&data.name,data.birDate,data.gender);
        insertNodeByHead(list,data);
        break;
    case 2:
        printf("***********查找信息***********\n");
        printf("请输入要查找的学生姓名：");
        scanf("%s",data.name);
        pMove = serachInfoByData(list,data.name);
        if(pMove==NULL)
        {
            printf("未找到相关信息！");
            system("pause");
        }
        else
        {
            printf("学号\t姓名\t生日\t性别\n");
            printf("%d\t%s\t%s\t%d\n",pMove->data.ID,pMove->data.name,pMove->data.birDate,pMove->data.gender);
        }
        break;
    case 3:
        printf("***********删除信息***********\n");
        printf("请输入要删除学生的姓名：");
        scanf("%s",data.name);
        deleteAppoinNode(list,data.name);
        break;
    case 4:
        printf("***********修改信息***********\n");
        printf("请输入修改学生的姓名");
        break;
    case 5:
        printf("***********输出信息***********\n");
        printf("请输入查找学生的姓名：");
        printList(list);
        break;
    case 6:
        printf("正常退出！\n");
        system("pause");
        exit(0);
        break;
    default:
        printf("出现错误，重新输入\n");
        system("pause");
        break;
    }
    writeInfoFile(list,"1.txt");

}
int main()
{
    readInfoFromFile(list,"1.txt");
    while(1)
    {
        menu();
        keyDown();
        system("pause");
        system("cls");
    }



    system("pause");
    return 0;
}
