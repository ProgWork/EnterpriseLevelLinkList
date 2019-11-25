#include"LinkList.h"
#include<string.h>
typedef struct PERSON {
	LinkNode* next;
	char name[64];
	int age;
}Person;

void Print(LinkList *list);
int Compare(LinkNode* data1, LinkNode* data2);
int main() {
	Person p1, p2, p3, p4, p5;
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	LinkList* list = Init();
	InsertByPos(list, 0, (LinkNode*)&p1);
	InsertByPos(list, 0, (LinkNode*)&p2);
	InsertByPos(list, 0, (LinkNode*)&p3);
	InsertByPos(list, 0, (LinkNode*)&p4);
	InsertByPos(list, 0, (LinkNode*)&p5);
	PrintLinkList(list, Print);
	Person p6, p7;
	strcpy_s(p6.name, "fff");
	strcpy_s(p7.name, "ggg");
	p6.age = 60;
	p7.age = 70;
	InsertTail(list, (LinkNode*)&p6);
	InsertTail(list, (LinkNode*)&p7);
	//DelByValue(list, (LinkNode*)&p2, Compare);
	DelByPos(list, 1);
	printf("===================================\n");
	PrintLinkList(list, Print);
	int pos = FindByValue(list, (LinkNode*)&p3,Compare);
	printf("位置为%d\n", pos);
	Person *p = (Person*)FindByPos(list, 1);
	printf("name为：%s,年龄为：%d\n", p->name, p->age);
	FreeSpace(list);
	system("pause");
	return 0;
}
void Print(LinkList *list) {
	if (list==NULL) {
		return;
	}
	LinkNode* pCurrent = list->head.next;
	while (pCurrent!=NULL)
	{
		Person *p = (Person*)pCurrent;
		printf("%s:%d\n", p->name, p->age);
		pCurrent = pCurrent->next;
	}
}
int Compare(LinkNode* data1, LinkNode* data2) {
	Person *p1 = (Person*)data1;
	Person *p2 = (Person*)data2;
	if (p1->name == p2->name&&p1->age == p2->age) {
		return 0;
	}
	else
	{
		return 1;
	}

}