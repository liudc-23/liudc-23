#include<stdio.h>
#include<string.h>
int strdelete(char *s1,char *s2)
{
	char *p1=s1,*p2=s2;
	char *q=s1,*ori=0;
	int len1=strlen(s1),len2=strlen(s2);
	int count=0;
	int num=0;
	for(;;){
		count=0;
		ori=p1;
		while(*p2!=0&&*p1==*p2){
			p1++;
			p2++;
			count++;
		}//�����Ƿ�ȫ�����
		p2=s2;//��ԭ
		p1=ori;
		if(count==len2){
			p1+=len2;
		}
		if(*p1==0)break;
		if(*p1==*p2)continue;//��ת����Ⱦ��Ȳ���ֵ�ٲ�һ���ٸ�ֵ
		*q=*p1;
		p1++;///���⣺��ת��ֱ�Ӵ�û���ټ��
		q++;
		num++;
	}
	return num;
}
int main()
{
	char s1[256]={0},s2[256]={0};
	int num;
	scanf("%s %s",s1,s2);
	num=strdelete(s1,s2);
	for(int i=0;i<num;i++)
		printf("%c",s1[i]);
	printf(" %d",num);
	return 0;
}
			


	