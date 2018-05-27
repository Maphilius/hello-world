#include<stdio.h>

int main()
{
	int number[100];
	int count;
	printf("Input count:\n");
	scanf("%d",&count);
	printf("Input numbers:\n");
	int i;
	for(i = 0; i < count; i++){
		scanf("%d",&number[i]);
	}
	int tmp,s = 0;
	printf("Output numbers:\n%d ",number[0]);
	for(i = 1; i < count; i++){
		tmp = number[i-1];
		if(number[i] == tmp){
			s++; 
		}else{
			printf("%d ",number[i]);
			tmp = number[i];
		}
	}
	printf("\nOutput count:\n%d",count - s);
	return 0;
}
