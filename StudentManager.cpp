#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<iostream>
#include "myList.h"
void menu()
{
    printf("��ѡ�����\n");
    printf("\t\*******************************\n");
    printf("\t\*          1 ����             *\n");
    printf("\t\*          2 ����             *\n");
    printf("\t\*          3 ɾ��             *\n");
    printf("\t\*          4 �޸�             *\n");
    printf("\t\*          5 ���             *\n");
    printf("\t\*          6 �˳�             *\n");
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
        printf("***********������Ϣ***********\n");
        printf("������ѧ��ѧ�ţ��������������£��Ա�");
        fflush(stdin);
        scanf("%d%s%s%d",data.ID,&data.name,data.birDate,data.gender);
        insertNodeByHead(list,data);
        break;
    case 2:
        printf("***********������Ϣ***********\n");
        printf("������Ҫ���ҵ�ѧ��������");
        scanf("%s",data.name);
        pMove = serachInfoByData(list,data.name);
        if(pMove==NULL)
        {
            printf("δ�ҵ������Ϣ��");
            system("pause");
        }
        else
        {
            printf("ѧ��\t����\t����\t�Ա�\n");
            printf("%d\t%s\t%s\t%d\n",pMove->data.ID,pMove->data.name,pMove->data.birDate,pMove->data.gender);
        }
        break;
    case 3:
        printf("***********ɾ����Ϣ***********\n");
        printf("������Ҫɾ��ѧ����������");
        scanf("%s",data.name);
        deleteAppoinNode(list,data.name);
        break;
    case 4:
        printf("***********�޸���Ϣ***********\n");
        printf("�������޸�ѧ��������");
        break;
    case 5:
        printf("***********�����Ϣ***********\n");
        printf("���������ѧ����������");
        printList(list);
        break;
    case 6:
        printf("�����˳���\n");
        system("pause");
        exit(0);
        break;
    default:
        printf("���ִ�����������\n");
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
