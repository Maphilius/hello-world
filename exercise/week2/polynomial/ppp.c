#include <stdio.h>
#include <stdlib.h>

/* 声明链表的结构体与单个项 */

typedef struct node {
	int coef;
	int exp;
	struct node *next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
} List;

/* 函数声明 */

void push(List* tmpList, int co, int ex);  // 添加链表节点 
void print(List *tmpList);                 // 打印链表 
void operate(List* list1, List* list2);      // 对多项式进行操作 
void Add(List* list1, List* list2);
void Minus(List* list1, List* list2);
void Multiply(List* list1, List* list2);

/* 将输入的项传入链表 */ 

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

/* 将得到的多项式链表打印*/ 

void print(List *tmpList){
	Node* p;
	printf("("); 
	for( p = tmpList->head; p; p = p->next){
		if( p->next == NULL){  // print前检测最后一项 
			if(p->exp == 0){  // 如果是常数项
				printf("%d", p->coef);  // print 常数项 
			}
			else{
				printf("%dX^%d", p->coef, p->exp);  //如果最后一项不是常数项 
			}                                
		}
		else{
		printf("%dX^%d+", p->coef, p->exp);   // 不是最后一项时 正常打印 
    	}
    }
    printf(")");
}

/* 获取操作运算符并操作 */

void operate(List* list1, List* list2){ 
	printf("请输入需要操作的指令： (+ / - / * )\n");
	char op;          // operator 居然是一个保留词！！！  
	scanf("%c", &op);
	while (op == 10) {
		scanf("%c", &op);
	}
	switch(op){
		case '+': Add(list1, list2); break;
		case '-': Minus(list1, list2); break;
		case '*': Multiply(list1, list2); break;
		default : printf("请输入合法的操作符\n"); operate(list1, list2);
  }
} 

/* 加法处理 */

void Add(List* list1, List* list2){
	
} 

/* 减法处理 */

void Minus(List* list1, List* list2){
	
} 

/* 乘法处理 */

void Multiply(List* list1, List* list2){
	
} 

int main()
{       
	List list1, list2, outlist;  // 定义三个链表 
	int n, i;               // for循环使用的操作变量 
	int co, exp;            // 定义多项式的单个项的系数与指数 
	
	/* 初始化链表 */ 
	
	list1.head = list1.tail = NULL;
	list2.head = list2.tail = NULL;
	outlist.head = outlist.tail = NULL;
	
	/* 获取多项式 1 */ 
	
	printf("多项式1的项数： \n");  // 首先获取多项式项数 
	scanf("%d",&n);
	printf("输入多项式1： ");      // 依次输入各项 
	for(i = 0; i < n; i++){
		scanf("%d %d", &co, &exp);
	    push(&list1, co, exp);
		}
	print(&list1);
	printf("\n");  // 不优雅的手动换行 
	
	/* 获取多项式 2 */ 
		
	printf("多项式2的项数： \n");
	scanf("%d",&n);
	printf("输入多项式2： ");
	for(i = 0; i < n; i++){
		scanf("%d %d", &co, &exp);
		push(&list2, co, exp);
		}
	print(&list2);
	printf("\n");  //不优雅的手动换行 
	
	/* 获取操作符号 */ 
	operate(&list1, &list2);
	
	return 0;
}


