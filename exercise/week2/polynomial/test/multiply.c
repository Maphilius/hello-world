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
