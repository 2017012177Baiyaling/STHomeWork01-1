#ifndef MYLIST_H
#define MYLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[20];
    int ID;
    char birDate[20];
    bool gender;
};

struct Node
{
    struct student data;
    struct Node* next;
};

struct Node* createList()
{
    struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
};

struct Node* createList(struct student)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
void insertNodeByHead(struct Node* headNode,char *name)
{
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}
//删除
void deleteAppoinNode(struct Node* headNode, char *name)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode = headNode;
    if(posNode == NULL)
    {
        printf("数据为空，无法删除！\n");
        return;
    }
    while(strcmp(posNode->data.name,name))
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
        if(posNode == NULL)
        {
            printf("未找到指定位置，无法删除！\n");
            return;
        }
    }
    posFrontNode->next = posNode->next;
    free(posNode);

}
//查找
struct Node* searchInfoByData(struct Node* headNode,char *name)
{
    struct Node* pMove = headNode->next;
    if(pMove == NULL)
    {
        return NULL;
    }
    while(strcmp(pMove->data.name,name))
    {
       pMove = pMove->next;
    }
    return pMove;
};

//读文件
void readInfoFromFile(struct Node* headNode, char *fileName)
{
    FILE *fp;
    struct student data;
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        fp=fopen(fileName, "w+");
    }
    while(fscanf(fp,"%d\t%s\t%s\t%d\n",data.ID,data.name,data.birDate,data.gender)!=EOF)
    {
        insertNodeByHead(headNode,data);
    }
    fclose(fp);
}
//写文件
void writeInfoFile(struct Node*, char *fileName)
{
    FILE *fp;
    fp = fopen(fileName,"w");
    if(fp==NULL)
    {
        printf("文件打开失败！");
        return;
    }
    struct Node* pMove = headNode->next;
    while(pMove)
    {
        fprintf(fp,"%d\t%s\t%s\t%d\n",pMove->data.ID,pMove->data.name,pMove->data.birDate,pMove->data.gender);
    }
    fclose(fp);
}

//输出
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;

    printf("学号\t姓名\t生日\t性别\n");
    while(pMove)
    {
        printf("%d\t%s\t%s\t%d\n",pMove->data.ID,pMove->data.name,pMove->data.birDate,pMove->data.gender);
        pMove = pMove->next;
    }
    printf("\n");
}

class myList
{
    public:
        myList();
        virtual ~myList();

    protected:

    private:
};

#endif // MYLIST_H
