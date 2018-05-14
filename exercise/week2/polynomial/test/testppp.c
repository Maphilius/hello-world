#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int coef;
	int exp;
	struct node *next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
} List;

/* �������� */

void push(List* tmpList, int co, int ex);  // �������ڵ� 
void print(List *tmpList);                 // ��ӡ���� 
void operate(List* list1, List* list2, List* outlist);      // �Զ���ʽ���в��� 
void Add(List* list1, List* list2, List* outlist);
void Minus(List* list1, List* list2, List* outlist);
void Multiply(List* list1, List* list2, List* outlist);
void BubbleSort(Node* o);  //ð������ �Ѷ���ʽ�Ĵ����Ӵ�С���� 
int sizeList(Node *pNode);
void merge(Node *pNode);

/* �������������� */ 

void push(List* tmpList, int co, int ex)
{
	Node* p = (Node*)malloc(sizeof(Node));
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

int sizeList(Node *pNode){
	int len = 0;
	while(pNode){
		len++;
		pNode = pNode->next;
	}
	return len;
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

void BubbleSort(Node* pNode) {
	    if (pNode == NULL) {  
//        printf("%s����ִ�У�����Ϊ�գ�ð������ʧ��\n",__FUNCTION__);  
        return ;  
    }else{  
  
        Node *pMove;  
        pMove = pNode;  
        //��Ҫ����(n-1)�α���,���ƴ���  
        int size = sizeList(pNode);  
        for (int i = 0; i < size; i++) {  
            while (pMove->next != NULL) {  
                if (pMove->exp < pMove->next->exp) {  
                    //ֻҪ�����������ڵ��elementԪ��ֵ�Ϳ�����  
                    int temp;  
                    temp = pMove->exp;  
                    pMove->exp = pMove->next->exp;  
                    pMove->next->exp = temp; 
					temp = pMove->coef;  
                    pMove->coef = pMove->next->coef;  
                    pMove->next->coef = temp;  
                }  
                pMove = pMove->next;  
            }  
            //ÿ�α���������pMove�����ƶ�������ͷ��  
            pMove = pNode;  
        }  
    }  
//    printf("%s����ִ�У�����ð���������\n",__FUNCTION__);  
      return;  
}

void merge(Node *pNode){
	int size = sizeList(pNode);
	int i;
	for(i = 0; i < size-1; i++){
		if(pNode->exp == pNode->next->exp){
			pNode->coef = pNode->coef + pNode->next->coef;
			pNode->next = pNode->next->next;
		}else{
			pNode = pNode->next;
		}
	} 
} 

int main()
{       
	List list1, list2, outlist;  // ������������ 
	int n, i;               // forѭ��ʹ�õĲ������� 
	int co, exp;            // �������ʽ�ĵ������ϵ����ָ�� 
	
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
	
	BubbleSort(list1.head);
	merge(list1.head);
	print(&list1);
	return 0;
}
