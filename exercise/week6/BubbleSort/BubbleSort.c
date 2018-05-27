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
	int tmp,j;
	for(i = 0; i < count - 1; i++){
		for(j = i + 1; j < count; j++){
			if (number[i] < number[j]){
				tmp = number[i];
				number[i] = number[j];
				number[j] = tmp;
			}
		}
	}
	printf("Output numbers:\n");
	for(i = 0; i < count; i++){
		printf("%d ",number[i]);
	}
	return 0;
} 
