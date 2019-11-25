#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE {
	LINKNODE* next;
}LinkNode;
typedef struct LINKLIST {
	LinkNode head;
	int size;
}LinkList;
typedef void(*MyPrint)(LinkList *list);
typedef int(*MyCompare)(LinkNode* data1,LinkNode* data2);

//��ʼ������
LinkList* Init();
//����
void InsertByPos(LinkList* list, int pos, LinkNode* mydata);
//����β��
void InsertTail(LinkList* list, LinkNode* mydata);
//��ֵɾ��
void DelByValue(LinkList* list, LinkNode* data, MyCompare Compare);
//��λ��ɾ��
void DelByPos(LinkList* list, int pos);
//��λ�ò��ң�����ֵ
LinkNode* FindByPos(LinkList* list, int pos);
//��ֵ���ң�����λ��
int FindByValue(LinkList* list, LinkNode* data,MyCompare Compare);
//��ӡ
void PrintLinkList(LinkList* list,MyPrint Print);
//�ͷſռ�
void FreeSpace(LinkList *list);
