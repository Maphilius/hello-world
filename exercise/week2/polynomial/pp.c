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
void operate(List* outlist, List* list1, List* list2);      // 对多项式进行操作 
void Add(List* outlist, List* list1, List* list2);
void Minus(List* outlist, List* list1, List* list2);
void Multiply(List* outlist, List* list1, List* list2);
void BubbleSort(Node* pNode);  //冒泡排序 把多项式的次数从大到小排序 
int sizeList(Node *pNode);
void merge(Node *pNode); //合并同类项 

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

/* 将链表冒泡排序从大到小 */

void BubbleSort(Node* pNode) {
	    if (pNode == NULL) {  
//        printf("%s函数执行，链表为空，冒泡排序失败\n",__FUNCTION__);  
        return ;  
    }else{  
  
        Node *pMove;  
        pMove = pNode;  
        //需要进行(n-1)次遍历,控制次数  
        int size = sizeList(pNode);  
        for (int i = 0; i < size; i++) {  
            while (pMove->next != NULL) {  
                if (pMove->exp < pMove->next->exp) {  
                    //只要交换这两个节点的element元素值就可以了  
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
            //每次遍历结束，pMove重新移动到链表头部  
            pMove = pNode;  
        }  
    }  
//    printf("%s函数执行，链表冒泡排序完成\n",__FUNCTION__);  
      return;  
}

/* 将得到的多项式链表打印*/ 

void print(List *tmpList){
	Node* p;
	int flag = 0;
	int lengthp;
	int lengthtmp = sizelist(tmpList->head)
	for( p = tmpList->head; p; p = p->next){
		if( p->next == NULL){  // print前检测最后一项 
			if(p->exp == 0){  // 如果是常数项
				printf("%d", p->coef);  // print 常数项 
			}else{
				printf("%dx^%d", p->coef, p->exp);  //如果最后一项不是常数项 
			}                                
		}else{
			printf("%dx^%d+", p->coef, p->exp);   // 不是最后一项时 正常打印 
    	}
    }
}

/*list length*/

int sizeList(Node *pNode){
	int len = 0;
	while(pNode){
		len++;
		pNode = pNode->next;
	}
	return len;
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


/* 获取操作运算符并操作 */

void operate(List* outlist, List* list1, List* list2){ 
	printf("请输入需要操作的指令： (+ / - / * )\n");
	char op;          // operator 居然是一个保留词！！！  
	scanf("%c", &op);
	while (op == 10) {
		scanf("%c", &op);
	}
	switch(op){
		case '+': Add(outlist, list1, list2); break;
		case '-': Minus(outlist, list1, list2); break;
		case '*': Multiply(outlist, list1, list2); break;
		default : printf("请输入合法的操作符\n"); operate(outlist, list1, list2);
   }
}

/* 加法处理 */

void Add(List* outlist, List* list1, List* list2){
	//把list1，list2并在outlist里 
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	int i;
	Node *p = list1->head;
	for(i = 0; i < size1 ; i++ ){
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	p = list2->head;
	for(i = 0; i < size2 ; i++ ){
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);
}

/* 减法处理 */

void Minus(List* outlist, List* list1, List* list2){
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	int i;
	Node *p = list1->head;
	for(i = 0; i < size1 ; i++ ){
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	p = list2->head;
	for(i = 0; i < size2 ; i++ ){
		push(outlist, -p->coef, p->exp);
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);	
} 

/* 乘法处理 */

void Multiply(List* outlist, List* list1, List* list2){
	int i,j;
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	Node *p = list1->head;
	Node *q; 
	for (i = 0; i < size1; i++){
		q = list2->head;
		for (j = 0; j < size2; j++){
			push(outlist, p->coef*q->coef, p->exp+q->exp);
			q = q->next;
		}
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);	
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
	operate(&outlist, &list1, &list2);
	print(&outlist);
	return 0;
}
// 1 2 3 4 5 6 7 8
