void print(List *tmpList){
	Node* p;
	for( p = tmpList->head; p; p = p->next){
		if( p->next == NULL){  // printǰ������һ�� 
			if(p->exp == 0){  // ����ǳ�����
				printf("%d", p->coef);  // print ������ 
			}
			else{
				printf("%dx^%d", p->coef, p->exp);  //������һ��ǳ����� 
			}                                
		}
		else{
		printf("%dx^%d+", p->coef, p->exp);   // �������һ��ʱ ������ӡ 
    	}
    }
}

