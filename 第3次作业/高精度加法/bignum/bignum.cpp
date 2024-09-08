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

swap(a);swap(b);//逆序后从个位算
for(i=0;i<len1;i++)
	a[i]=a[i]-48;
for(i=0;i<len2;i++)
	b[i]=b[i]-48;

if(len1<len2)len1=len2;//for里面的长度为大值
for(i=0;i<len1+1;i++){
	o[i]=a[i]+b[i];
	if(flag==1){o[i]++;flag=0;}
	if(o[i]>9){flag=1;o[i]=o[i]-10;}
		}//最后一位如果进位没有加上,多读一位前面就会有0

for(i=0;i<len1+1;i++)o[i]+=48;//转换为字符串的数字
if(o[len1]=='0')o[len1]=0;
swap(o);
printf("%s",o);
return 0;

}
void swap(char a[])//逆序函数
{int i,temp;
for(i=0;i<strlen(a)/2;i++)
	{temp=a[i];
	a[i]=a[strlen(a)-i-1];
	a[strlen(a)-i-1]=temp;}
}