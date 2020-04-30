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
//ɾ��
void deleteAppoinNode(struct Node* headNode, char *name)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode = headNode;
    if(posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ����\n");
        return;
    }
    while(strcmp(posNode->data.name,name))
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
        if(posNode == NULL)
        {
            printf("δ�ҵ�ָ��λ�ã��޷�ɾ����\n");
            return;
        }
    }
    posFrontNode->next = posNode->next;
    free(posNode);

}
//����
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

//���ļ�
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
//д�ļ�
void writeInfoFile(struct Node*, char *fileName)
{
    FILE *fp;
    fp = fopen(fileName,"w");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        return;
    }
    struct Node* pMove = headNode->next;
    while(pMove)
    {
        fprintf(fp,"%d\t%s\t%s\t%d\n",pMove->data.ID,pMove->data.name,pMove->data.birDate,pMove->data.gender);
    }
    fclose(fp);
}

//���
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;

    printf("ѧ��\t����\t����\t�Ա�\n");
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
