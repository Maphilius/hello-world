#include<stdio.h>

typedef struct _node {
	int coef;
	int exp;
	struct _node *next;
} Node;

typedef struct _list {
	Node* head;
	Node* tail;
} List;

void add(List* pList, int, int);
void print(List *pList);

int main()
{
	Node* head = NULL;
	List list1, list2, list;
	int n,i;
	int co,exp;
	list1.head = list1.tail = NULL;
	// scanf list1,list2
	printf("多项式1的项数： ");
	scanf("%d",&n);
	for(i=0)
		scanf("%d %d", &co, &exp);
		add(&list1, co, exp);
	print(&list1);
//	list2.head = list2.tail = NULL;
//	do{
//		scanf("%d", &number);
//		if(number != -1) {
//			add(&list2, number);
//		}
//	}while(number != -1);
	//make the new list
//	Node* p, *q;
//	list.head = list.tail = NULL;
//	p =list1.head;
//	q =list2.head;
//	if (list1.tail->value<list2.tail->value){
//		while(p){
//			if(p->value < q->value){
//				add(&list, p->value);
//				p = p->next;
//			}else{
//				add(&list, q->value);
//				q = q->next;
//			}
//		}
//		while(q){
//			add(&list, q->value);
//			q = q->next;
//		}
//	}else{
//		while(q){
//			if(p->value < q->value){
//				add(&list, p->value);
//				p = p->next;
//			}else{
//				add(&list, q->value);
//				q = q->next;
//			}
//		}
//		while(p){
//			add(&list, p->value);
//			p = p->next;
//		}
//	}
//	print(&list);
	return 0;
}

void add(List* pList, int co, int ex)
{
	Node*p = (Node*)malloc(sizeof(Node));
	p->coef = co;
	p->exp = ex;
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
		printf("%dX%d ", p->coef, p->exp);
	}
	printf("\n");
}
