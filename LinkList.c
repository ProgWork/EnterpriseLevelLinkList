#include"LinkList.h"


//��ʼ������
LinkList* Init() {
	LinkList *list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//��λ�ò���
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
	//��ѯ����λ��
	for (int i = 0; i < pos;i++) {
		pCurrent = pCurrent->next;
	}
	mydata->next = pCurrent->next;
	pCurrent->next = mydata;
	list->size++;
}
//����β��
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
//��ֵɾ��
void DelByValue(LinkList* list, LinkNode* data, MyCompare Compare) {
	if (list==NULL) {
		return;
	}
	if (data==NULL) {
		return;
	}
	//���� 
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
//��λ��ɾ��
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
//��λ�ò��ң�����ֵ
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
//��ֵ���ң�����λ��
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

//��ӡ
void PrintLinkList(LinkList* list,MyPrint Print) {
	Print(list);
}
//�ͷſռ�
void FreeSpace(LinkList *list) {
	if (list==NULL) {
		return;
	}
	free(list);
}