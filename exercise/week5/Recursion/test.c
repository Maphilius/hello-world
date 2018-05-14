#include <stdio.h>
#include "string.h"

void charToChar(char v[]);
void ListMnemonics(char str[][4],int length);

char p[12];

main()
{
int i;
char *v;
//clrscr();
printf("Please input not more than 12 telphone numbers:");
gets(v);

charToChar(v);

getch();
}

void charToChar(char v[])
{
int i,j,*num,length;
char str[12][4];
char *number[]=

{"ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"};

length=strlen(v);

for(i=0;i<length;i++)
{
num[i]=v[i]-48;
}

for(i=0;i<length;i++)
{
for(j=0;j<3;j++)
{
str[i][j]=number[num[i]-2][j];
}
str[i][j]='\0';
}


ListMnemonics(str,length);

}

void ListMnemonics(char str[][4],int length)
{
int i;

if(length==0)
{
printf("%s ",strrev(p));
strrev(p);
}

else
{
for(i=0;i<3;i++)
{
p[length-1]=str[0][i];
ListMnemonics(++str,--length);
--str;
++length;
}

}

}
