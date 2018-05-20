#include <stdio.h>
#include <stdlib.h>

int *division;
int n;
void Decompose_Recursion(int now, int time, int pre);
void Decompose_Circulation();

int main(){
	int mode;
	printf("Please input the target positive integer.\n");
	scanf("%d", &n);
	printf("Algorithm mode: 1. Recursion 2. Circulation\n");
	scanf("%d", &mode);
	division = (int*)malloc(n * sizeof(int));
	switch(mode){
		case 1:
	        Decompose_Recursion(0, 0, n - 1);
	        break;
	    case 2:
	    	Decompose_Circulation();
	    	break;
	}
	system("pause");
	return 0;
}

void Decompose_Recursion(int now, int term, int pre){
	int i;
	if(now > n) return;
	if(now == n){
		printf("%d = ", n);
		for(i = 0; i < term - 1; i++){
			printf("%d+", division[i]);
		}
		printf("%d\n", division[i]);
	}else{
		for(i = pre; i > 0; i--){
			division[term] = i;
			Decompose_Recursion(now + i, term + 1, i);
		}
	}
}

void Decompose_Circulation(){
	int i, div = 0, term, d;
	free(division);
	division = (int*)malloc(n * sizeof(int));
    division[0] = n - 1;
    division[1] = 1;
    div = 2;
    while(1){
    	printf("%d = ", n);
        for (i = 0; i < div - 1; i++){
        	printf("%d+", division[i]);
		}
        printf("%d\n", division[div - 1]);
        term = 0;
        do{
            term += division[--div];
        }while (div >= 0 && division[div] == 1);
        if (div == -1) break; 
        d = division[div] - 1;
        if (d == 1){
            while (term > 0){
                division[div++] = 1;
                term--;
            }
        }else{
            do{
                division[div++] = d;
                term -= d;
            }while (term >= d);
            if (term != 0) division[div++] = term;
        }
    }
}
