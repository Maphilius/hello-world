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

rationalT AddRational(rationalT r1,rationalT r2)
{
	rationalT retval;
	retval.num=r1.den*r2.num+r1.num*r2.den;
	retval.den=r1.den*r2.den;
	int a=(retval.num<=retval.den)?retval.num:retval.den;
	int b=(retval.num>=retval.den)?retval.num:retval.den;
	int h;
	if (a==b) {
		retval.num=1;
		retval.den=1;
	}else{
		do{
			h=b;
			b=b%a;
			a=h;
		}while(b>0);
		retval.num=retval.num/a;
		retval.den=retval.den/a;
	}
	return retval;
}

rationalT MultiplyRational(rationalT r1,rationalT r2)
{
	rationalT retval;
	retval.num=r2.num*r1.num;
	retval.den=r1.den*r2.den;
	int a=(retval.num<=retval.den)?retval.num:retval.den;
	int b=(retval.num>=retval.den)?retval.num:retval.den;
	int h;
	if (a==b) {
		retval.num=1;
		retval.den=1;
	}else{
		do{
			h=b;
			b=b%a;
			a=h;
		}while(b>0);
		retval.num=retval.num/a;
		retval.den=retval.den/a;
	}
	return retval;	
}

rationalT GetRational(rationalT d)
{
	rationalT retval;
	retval.num=d.num;
	retval.den=d.den;
	int a=(retval.num<=retval.den)?retval.num:retval.den;
	int b=(retval.num>=retval.den)?retval.num:retval.den;
	int h;
	if (a==b) {
		retval.num=1;
		retval.den=1;
	}else{
		do{
			h=b;
			b=b%a;
			a=h;
		}while(b>0);
		retval.num=retval.num/a;
		retval.den=retval.den/a;
	}
//	printf("%d/%d \n",retval.num,retval.den);
	return retval;	
}

void PrintRational(rationalT r)
{
	int a=r.num;
	int b=r.den;
	printf("%d/%d",a,b);
}
