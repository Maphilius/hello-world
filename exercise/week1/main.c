#include "rational.h"
#include<stdio.h>
int main()
{
	rationalT r3,r,sum0,sum;
	rationalT *p1=&r3;
	int n=0;
	sum0.num=0;
	sum0.den=1;
	printf("This program adds a list of rational numbers.\n");
	printf("Signal ehd of list with a 0.\n");
	printf(" ? ");
	while (scanf("%d",&r3.num),r3.num){
		scanf("/%d",&r3.den);
		rationalT *p1=GetRational(r3);
		rationalT *p2=AddRational(sum0,*p1);
		free(p1);
		sum0.den=p2->den;
		sum0.num=p2->num;
		free(p2);
		printf(" ? ");
	}
	printf("The total is %d/%d",sum0.num,sum0.den);
	return 0;
}
