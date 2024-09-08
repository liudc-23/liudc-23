#include<stdio.h>
#include<string.h>
int main()
{int ch=0,space=0,num=0,oth=0;
int flag=0,i;
char c,ary[201];
gets(ary);
for(i=0;ary[i]!='\0';i++)
	{c=ary[i];
		if(c>='A'&&c<='Z'){
			flag=1;ary[i]=c+32;}
		if(c>='a'&&c<='z'){
			flag=1;ary[i]=c-32;}

		if(c==' ')flag=2;
		if(c>='0'&&c<='9')flag=3;
switch(flag)
{case 1:ch++;break;
case 2:space++;break;
case 3:num++;break;
default:oth++;break;}
flag=0;
}
printf("%s\n",ary);
	printf("%d\n%d\n%d\n%d\n",ch,space,num,oth);
	return 0;
}
