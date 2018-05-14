#include"rational.h"
#include<math.h>
#include<stdio.h>
rationalT CreateRational(int a, int b)
{
	rationalT retval;
	retval.num = a;
	retval.den = b;
	return retval;
}

rationalT *AddRational(rationalT r1,rationalT r2)
{
	rationalT retval;
	rationalT *p=malloc(sizeof(rationalT)); 
	retval.num=r1.den*r2.num+r1.num*r2.den;
	retval.den=r1.den*r2.den;
	int a=retval.num;
	int b=retval.den;
	int h;
	while(b!=0){
		h=a%b;a=b;b=h;
	}
	retval.num=retval.num/a;
	retval.den=retval.den/a;
	p->den=retval.den;
	p->num=retval.num;
	return p;
}

rationalT *MultiplyRational(rationalT r1,rationalT r2)
{
	rationalT retval;
	rationalT *p=malloc(sizeof(rationalT));
	retval.num=r2.num*r1.num;
	retval.den=r1.den*r2.den;
		int a=retval.num;
	int b=retval.den;
	int h;
	while(b!=0){
		h=a%b;a=b;b=h;
	}
	retval.num=retval.num/a;
	retval.den=retval.den/a;
	p->den=retval.den;
	p->num=retval.num;
	return p;	
}

rationalT *GetRational(rationalT d)
{
	rationalT retval;
	rationalT *p=malloc(sizeof(rationalT));
	retval.num=d.num;
	retval.den=d.den;
	int a=retval.num;
	int b=retval.den;
	int h;
	while(b!=0){
		h=a%b;a=b;b=h;
	}
	retval.num=retval.num/a;
	retval.den=retval.den/a;
	p->den=retval.den;
	p->num=retval.num;
	return p;	
}

void PrintRational(rationalT r)
{
	int a=r.num;
	int b=r.den;
	printf("%d/%d",a,b);
}
