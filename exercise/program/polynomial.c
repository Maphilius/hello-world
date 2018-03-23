#include<stdlib.h>

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
void plus(List* p1,List* p2);

int main()
{
	Node* head = NULL;
	List list1, list2, list;
	
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
