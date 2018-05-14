#include "rational.h"
#include<stdio.h>
int main()
{
	rationalT r3,r,sum0,sum;
	sum.num=0;
	printf("This program adds a list of rational numbers.\n");
	printf("Signal ehd of list with a 0.\n");
	do{
		printf(" ? ");
		scanf("%d/%d",&r3.num,&r3.den);
		GetRational(r3);
//		printf("%d/%d",r3.num,r3.den);
//		sum0=AddRational(sum0,r3);
	}while (r3.num==0);
	printf("The total is %d/%d",sum0.num,sum0.den);
	return 0;
}
