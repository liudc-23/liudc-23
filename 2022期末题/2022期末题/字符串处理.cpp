#include<stdio.h>
#include<string.h>
void InputStr(char str1[],char *str2,double *ptr){
	scanf("%[^\n]",str1);
	printf("%s\n",str1);
	getchar();
	gets(str2);
	printf("%s\n",str2);
	scanf("%lf",ptr);
	printf("%.9e\n",*ptr);
}
void Double2Str(char str_from_d[],double d){
	if(d>0)
		str_from_d[0]='+';
	if(d<0){
		str_from_d[0]='-';
		d=-d;
	}
	int intpart[100]={0};
	int intd=(int)d;
	int i=0;
	int intd_copy=intd;
	for(i=0;intd_copy>0;i++){
		intpart[i]=intd_copy%10;
		intd_copy/=10;
	}
	for(int j=1;j<i+1;j++){
		str_from_d[j]=intpart[i-j]+'0';
	}
	int len1=strlen(str_from_d);
	str_from_d[len1]='.';
	int pointpart[100];
	long long int point=(d-intd)*1000000000;
	int j=0;
	for(j=0;point>0;j++){
		pointpart[j]=point%10;
		point/=10;
	}
	for(int k=1;k<j+1;k++){
		str_from_d[len1+k]=pointpart[j-k]+'0';
	}
	for(int i=0;i<strlen(str_from_d);i++){
	printf("%d",str_from_d[i]);
	}
}
int main()
{
	char str1[100],str2[100];
	double d;
	InputStr(str1,str2,&d);
	char str_from_d[1000]={0};
	Double2Str(str_from_d,d);
}