#include<stdio.h>
#include<string.h>
int isnum(char ch);
void analysis(char *s,int vec[]);
void turn_to_num(char s[]);
int polycomb(char *s1,char *s2,char *p);
int main()
{
	char s1[100]={0},s2[100]={0};
	int vec[11]={0},vec1[11]={0},vec2[11]={0};
	char buffer[100]={0};
	char *p=buffer;
	int last=0;
	gets(s1);
	gets(s2);
	turn_to_num(s1);
	turn_to_num(s2);
	analysis(s1,vec1);
	analysis(s2,vec2);
	for(int i=0;i<11;i++){
		vec[i]=vec1[i]+vec2[i];
		if(vec[i]!=0)last=i;
	}
	if(vec[last]!=0&&last!=1&&last!=0){
			if(vec[last]!=1&&vec[last]>0)
				printf("%dx^%d",vec[last],last);
			if(vec[last]==1)
				printf("x^%d",last);
			if(vec[last]==-1)
				printf("-x^%d",last);
			if(vec[last]<0&&vec[last]!=-1)
				printf("%+dx^%d",vec[last],last);
		}
	for(int i=last-1;i>1;i--){
		if(vec[i]!=0){
			if(vec[i]!=1&&vec[i]!=-1)
				printf("%+dx^%d",vec[i],i);
			if(vec[i]==1)
				printf("+x^%d",i);
			if(vec[i]==-1)
				printf("-x^%d",i);
		}
	}
	if(vec[1]!=0){
			if(vec[1]!=1&&vec[1]!=-1)
				printf("%+dx",vec[1]);
			if(vec[1]==1&&last!=1)
				printf("+x");
			if(vec[1]==1&&last==1)//最高位是x时很麻烦
				printf("x");
			if(vec[1]==-1)
				printf("-x");
	}
	if(vec[0]!=0)
		printf("%+d",vec[0]);
	printf(" %d",vec[last]);
}
void turn_to_num(char s[]){
	for(int i=0;i<strlen(s);i++)
		if(s[i]>='0'&&s[i]<='9')
			s[i]-='0';
}
int isnum(char ch)
{
	if(ch>=0&&ch<=9)
		return 1;
	else 
		return 0;
}
void analysis(char *s,int vec[])
{
	int i=0;
	int len=strlen(s);
	int flag=0;
	char *p=s+len-1;
	if((s[len-1]>=0&&s[len-1]<=9)&&(s[len-2]=='+'||s[len-2]=='-')){//有bug第一位是数字但不一定是常数项
		if(s[len-2]=='+')vec[0]=s[len-1];
		if(s[len-2]=='-')vec[0]=s[len-1]*(-1);
	}
	else 
		vec[0]=0;//是否有常数项
	while(p>=s){
		if(*p=='^'){
			i=*(p+1);
			flag=1;
		}
		if(*p=='+'&&flag==1){
			if(isnum(*(p+1)))
				vec[i]=*(p+1);
			else
				vec[i]=1;
		}
		if(*p=='-'&&flag==1){
			if(isnum(*(p+1)))
				vec[i]=*(p+1)*(-1);
			else
				vec[i]=(-1);
		}
		if(*p=='x'&&flag==0){//读到x的一次前面的系数了
			if(isnum(*(p-1))){
				if(*(p-2)=='+')	vec[1]=*(p-1);
				if(*(p-2)=='-') vec[1]=(*(p-1))*(-1);
			}
			else {//系数为1时不写出
				if(*(p-1)=='+')	vec[1]=1;
				if(*(p-1)=='-') vec[1]=(-1);
			}
		}
		if(p==s&&flag==1){//第一个数前面没有符号时（有-的话前面的已经可以写入vec了）
			if(isnum(*p))
				vec[i]=*p;//此时不用考虑*p为负
			if(*p=='x')
				vec[i]=1;
		}
		if(p==s&&flag==0&&*p=='x')
			vec[1]=1;
		p--;
	}
	return;
}
