#include<stdlib.h>
#include<stdio.h>

typedef struct _node {
	int coff;
	int index;
	struct _node *next;
} Node;

typedef struct _list {
	Node* head;
	Node* tail;
} List;

void add(List* pList, int c, int i);
void print(List *pList);
void plus(List* p1,List* p2);

int main()
{
	Node* head = NULL;
	List list1, list2, list;
	int co,in;
	char signal;
	list1.head = list1.tail = NULL;
	// scanf list1,list2
	do{
		scanf("%d,%d,%c",&co,&in,&signal);
		if(signal != '#') {
			add(&list1, co, in);
		}
	}while(signal != '#');
	//print list1
	print(&list1);
	return 0;
}

void add(List* pList, int c, int i){
	Node*p = (Node*)malloc(sizeof(Node));
	p->coff = c;
	p->index = i;
	p->next = NULL;
	Node*last = pList->tail;
	if( last ) {
		pList->tail = last->next = p;	
	} else {
		pList->head = pList->tail = p;
	}
}

void print(List *pList){
	Node* p;
	for( p = pList->head; p; p = p->next){
		printf("%d,%d ", p->coff, p->index);
	}
	printf("\n");
}
