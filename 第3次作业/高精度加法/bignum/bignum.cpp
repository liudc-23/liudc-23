#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(char a[]);
int main()
{ char a[100]={0},b[100]={0};
char o[100]={0};
int flag=0,len1,len2;
int i;
gets(a);gets(b);
len1=strlen(a);len2=strlen(b);

swap(a);swap(b);//�����Ӹ�λ��
for(i=0;i<len1;i++)
	a[i]=a[i]-48;
for(i=0;i<len2;i++)
	b[i]=b[i]-48;

if(len1<len2)len1=len2;//for����ĳ���Ϊ��ֵ
for(i=0;i<len1+1;i++){
	o[i]=a[i]+b[i];
	if(flag==1){o[i]++;flag=0;}
	if(o[i]>9){flag=1;o[i]=o[i]-10;}
		}//���һλ�����λû�м���,���һλǰ��ͻ���0

for(i=0;i<len1+1;i++)o[i]+=48;//ת��Ϊ�ַ���������
if(o[len1]=='0')o[len1]=0;
swap(o);
printf("%s",o);
return 0;

}
void swap(char a[])//������
{int i,temp;
for(i=0;i<strlen(a)/2;i++)
	{temp=a[i];
	a[i]=a[strlen(a)-i-1];
	a[strlen(a)-i-1]=temp;}
}