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

//初始化链表
LinkList* Init();
//插入
void InsertByPos(LinkList* list, int pos, LinkNode* mydata);
//插入尾部
void InsertTail(LinkList* list, LinkNode* mydata);
//按值删除
void DelByValue(LinkList* list, LinkNode* data, MyCompare Compare);
//按位置删除
void DelByPos(LinkList* list, int pos);
//按位置查找，返回值
LinkNode* FindByPos(LinkList* list, int pos);
//按值查找，返回位置
int FindByValue(LinkList* list, LinkNode* data,MyCompare Compare);
//打印
void PrintLinkList(LinkList* list,MyPrint Print);
//释放空间
void FreeSpace(LinkList *list);
