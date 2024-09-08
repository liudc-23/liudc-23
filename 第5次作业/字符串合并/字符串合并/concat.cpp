#include<stdio.h>
#include<string.h>
char *strcattype(char *s1,char *s2,int type)
{
	char *p;
	if(type==1){
		p=s1+strlen(s1);
		for(int i=0;i<strlen(s2);i++){
			*p=s2[i];
			p++;
		}
		*p=0;
		return s1;
	}
	if(type==2){
		p=s2+strlen(s2);
		for(int i=0;i<strlen(s1);i++){
			*p=s1[i];
			p++;
		}
		*p=0;
		return s2;
	}
}
int main()
{
	char *strcattype(char *s1,char *s2,int type);
	char s1[256],s2[256];
	int type;
	int sum=0;
	scanf("%s %s",s1,s2);
	scanf("%d",&type);
	printf("%s",strcattype(s1,s2,type));
	if(type==1)
		for(int i=0;s1[i]!=0;i++)
			sum++;
	if(type==2)
		for(int i=0;s2[i]!=0;i++)
			sum++;
	printf(" %d",sum);
	return 0;
}
	