#include<stdio.h>
int main()
{int n,s,k[100]={0},m[100]={0};
int next[100];
int a[100]={0};
int i,j;
int tell=1,now;//��������ѭ����tell��¼
scanf("%d%d",&n,&s);
for(i=0;i<100;i++)next[i]=i+1;
next[n-1]=0;//��nextʹ������һ��Ȧ
now=n;
for(j=0;j<s;j++)
	scanf("%d%d",&k[j],&m[j]);
for(j=0;j<s;j++){
	for(i=0;i<n;i++)a[i]=0;
	tell=1;
	now=n;//�������
	for(i=k[j]-1;now!=1;i=next[i]){
		if(a[i]==0&&tell==m[j]){//0��ʾδ�˳���1��ʾ�˳�
			a[i]=1;
			tell=1;
			now--;}
		if(a[i]==0){
			tell++;}
	}
		for(i=0;i<n;i++)
			{if(a[i]==0)printf("%d\n",i+1);
				}
	
}
return 0;
}



