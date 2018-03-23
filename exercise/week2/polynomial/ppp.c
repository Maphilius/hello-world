#include<stdio.h>

/* ��������Ľṹ���뵥���� */

typedef struct node {
	int coef;
	int exp;
	struct node *next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
} List;

void push(List* tmpList, int co, int ex);  // �������ڵ� 
void print(List *tmpList);                 // ��ӡ���� 
void operate(List *tmpList, char op)       // �Զ���ʽ���в��� 

int main()
{       
	List list1, list2, outlist;  // ������������ 
	int n, i;               // forѭ��ʹ�õĲ������� 
	int co, exp;            // �������ʽ�ĵ������ϵ����ָ�� 
	char op;          // operator ��Ȼ��һ�������ʣ����� 
	
	/* ��ʼ������ */ 
	
	list1.head = list1.tail = NULL;
	list2.head = list2.tail = NULL;
	outlist.head = outlist.tail = NULL;
	
	/* ��ȡ����ʽ 1 */ 
	
	printf("����ʽ1�������� \n");  // ���Ȼ�ȡ����ʽ���� 
	scanf("%d",&n);
	printf("�������ʽ1�� ");      // ����������� 
	for(i = 0; i < n; i++){
		scanf("%d %d", &co, &exp);
	    push(&list1, co, exp);
		}
	print(&list1);
	printf("\n");  // �����ŵ��ֶ����� 
	
	/* ��ȡ����ʽ 2 */ 
		
	printf("����ʽ2�������� \n");
	scanf("%d",&n);
	printf("�������ʽ2�� ");
	for(i = 0; i < n; i++){
		scanf("%d %d", &co, &exp);
		push(&list2, co, exp);
		}
	print(&list2);
	printf("\n");  //�����ŵ��ֶ����� 
	printf("��������Ҫ������ָ� (+ / - / *)\n");  
	return 0;
}


/* �������������� */ 

void push(List* tmpList, int co, int ex)
{
	Node*p = (Node*)malloc(sizeof(Node));
	p->coef = co;
	p->exp = ex;
	p->next = NULL;
	Node* last = tmpList->tail;
	if(last) {
		tmpList->tail = last->next = p;	
	} else {
		tmpList->head = tmpList->tail = p;
	}
}

/* ���õ��Ķ���ʽ�����ӡ*/ 

void print(List *tmpList){
	Node* p;
	printf("("); 
	for( p = tmpList->head; p; p = p->next){
		if( p->next == NULL){  // printǰ������һ�� 
			if(p->exp == 0){  // ����ǳ�����
				printf("%d", p->coef);  // print ������ 
			}
			else{
				printf("%dX^%d", p->coef, p->exp);  //������һ��ǳ����� 
			}                                
		}
		else{
		printf("%dX^%d+", p->coef, p->exp);   // �������һ��ʱ ������ӡ 
    	}
    }
    printf(")");
}
