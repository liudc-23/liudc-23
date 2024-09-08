#include<stdio.h>
#include<string.h>
#define N ' '
int main()
{
	int int2call(int a,char *p);
	unsigned int a=0;
	char buffer[10000]={0};
	int num=0;
	scanf("%d",&a);
	if(a>0&&a<65535){
		num=int2call(a,buffer);
		printf("%s",buffer);
	}
	else
		printf("ERROR");
	return 0;
}
int int2call(int a,char *p)
{
	int sto[5]={0};
	int flag=0;
	int tho,hun,ten;
	char *p0=p;
	char *hunch[]={"0","THOUSAND","HUNDRED"};
	char *onech[]={"0","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN",
					"ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN",
					"SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN",};//0占位保证字符串和数据的对应关系
	char *tench[]={"0","TEN","TWTENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
	for(int i=0;i<5;i++){
		sto[i]=a%10;
		a/=10;
	}
	tho=sto[4]*10+sto[3];
	hun=sto[2];
	ten=sto[1]*10+sto[0];
	if(tho>0){
		if(tho<20){//小于20时一种情况
			strcpy(p,onech[tho]);
			p+=strlen(onech[tho]);
			*p=N;p++;
		}
		else {
			flag=tho%10;
			if(flag==0){//能整除时一种情况
				strcpy(p,tench[tho/10]);
				p+=strlen(tench[tho/10]);
				*p=N;p++;
			}
			else{
				strcpy(p,tench[tho/10]);
				p+=strlen(tench[tho/10]);
				*p=N;p++;
				strcpy(p,onech[flag]);
				p+=strlen(onech[flag]);
				*p=N;p++;
			}
		}
		strcpy(p,hunch[1]);
		p+=strlen(hunch[1]);
		*p=N;p++;
	}
	if(hun>0){
		strcpy(p,onech[hun]);
		p+=strlen(onech[hun]);
		*p=N;p++;
		strcpy(p,hunch[2]);
		p+=strlen(hunch[2]);
		*p=N;p++;
	}
	if(ten>0){
		if(ten<20){//小于20时一种情况
			strcpy(p,onech[ten]);
			p+=strlen(onech[ten]);
			*p=N;p++;
		}
		else {
			flag=ten%10;
			if(flag==0){//能整除时一种情况
				strcpy(p,tench[ten/10]);
				p+=strlen(tench[ten/10]);
			}
			else{
				strcpy(p,tench[ten/10]);
				p+=strlen(tench[ten/10]);
				*p=N;p++;
				strcpy(p,onech[flag]);
				p+=strlen(onech[flag]);
			}
		}
	}
	return strlen(p0);
}

