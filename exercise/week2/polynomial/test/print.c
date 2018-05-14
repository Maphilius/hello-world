void print(List *tmpList){
	Node* p;
	for( p = tmpList->head; p; p = p->next){
		if( p->next == NULL){  // print前检测最后一项 
			if(p->exp == 0){  // 如果是常数项
				printf("%d", p->coef);  // print 常数项 
			}
			else{
				printf("%dx^%d", p->coef, p->exp);  //如果最后一项不是常数项 
			}                                
		}
		else{
		printf("%dx^%d+", p->coef, p->exp);   // 不是最后一项时 正常打印 
    	}
    }
}

