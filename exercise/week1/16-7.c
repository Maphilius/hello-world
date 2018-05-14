#include<stdio.h>
#include<string.h>

struct cash{
	char state[10];
	double money;
}c[5];

int main(){
	char ch1[10],ch2[10];
	double n;
	int i,j,a,b;
	FILE * fp = fopen("exchange.dat", "r");
	fscanf(fp,"%s %lf\n",c[0].state,&c[0].money);
	fscanf(fp,"%s %lf\n",c[1].state,&c[1].money);
	fscanf(fp,"%s %lf\n",c[2].state,&c[2].money);
	fscanf(fp,"%s %lf\n",c[3].state,&c[3].money);
	fscanf(fp,"%s %lf\n",c[4].state,&c[4].money);
    printf("Convert form: ");
    scanf("%s",ch1);
    for (i=0;i<5;i++){
    	if(strcmp(ch1,c[i].state)==0)a=i;
	}
    printf("Into: ");
    scanf("%s",ch2);
    for (j=0;j<5;j++){
    	if(strcmp(ch2,c[j].state)==0)b=j;
	}
    printf("How many units of type %s? ",ch1);
    scanf("%lf",&n);
    printf("%.0f %s = %.1f %s",n,ch1,n*c[a].money/c[b].money,ch2);
    return 0;
}

