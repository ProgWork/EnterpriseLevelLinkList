#include"LinkList.h"


//初始化链表
LinkList* Init() {
	LinkList *list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//按位置插入
void InsertByPos(LinkList *list, int pos,LinkNode* mydata) {
	if (list==NULL) {
		return;
	}
	if (mydata==NULL) {
		return;
	}
	if (pos < 0 || pos>list->size) {
		pos = list->size;
	}
	LinkNode* pCurrent = &list->head;
	//查询插入位置
	for (int i = 0; i < pos;i++) {
		pCurrent = pCurrent->next;
	}
	mydata->next = pCurrent->next;
	pCurrent->next = mydata;
	list->size++;
}
//插入尾部
void InsertTail(LinkList *list, LinkNode* mydata) {
	if (list==NULL) {
		return;
	}
	if (mydata==NULL) {
		return;
	}
	LinkNode* pCurrent = &list->head;
	while (pCurrent->next!=NULL)
	{
		pCurrent = pCurrent->next;
	}
	mydata->next = pCurrent->next;
	pCurrent->next = mydata;
	list->size++;
}
//按值删除
void DelByValue(LinkList* list, LinkNode* data, MyCompare Compare) {
	if (list==NULL) {
		return;
	}
	if (data==NULL) {
		return;
	}
	//查找 
	LinkNode* pCurrent = &list->head;
	while (pCurrent->next!=NULL)
	{
		if (Compare(pCurrent->next, data)==0) {
			pCurrent->next = pCurrent->next->next;
			list->size--;
			break;
		}
		pCurrent = pCurrent->next;
	}
}
//按位置删除
void DelByPos(LinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos<0 || pos>=list->size) {
		return;
	}
	LinkNode* pCurrent = &list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pCurrent->next->next;
	list->size--;
}
//按位置查找，返回值
LinkNode* FindByPos(LinkList* list, int pos) {
	if (list == NULL) {
		return NULL;
	}
	LinkNode* pCurrent = list->head.next;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}
//按值查找，返回位置
int FindByValue(LinkList* list, LinkNode* data, MyCompare Compare) {
	if (list == NULL) {
		return -1;
	}
	if (data == NULL) {
		return -1;
	}
	int index = 0;
	LinkNode* pCurrent = list->head.next;
	while (pCurrent!=NULL)
	{
		if (Compare(pCurrent, data) == 0) {
			return index;
		}
		index++;
		pCurrent = pCurrent->next;
	}
	return -1;
}

//打印
void PrintLinkList(LinkList* list,MyPrint Print) {
	Print(list);
}
//释放空间
void FreeSpace(LinkList *list) {
	if (list==NULL) {
		return;
	}
	free(list);
}