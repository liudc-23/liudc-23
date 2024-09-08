#include<stdio.h>
#include<stdlib.h>
int main()
{
	int myscanf(int a[][2]);
	void sort(int mat[][2],int n);
	int unite(int a[][2],int na,int b[][2],int nb,int c[][2]);
	void sort1(int c[][2],int n);
	int search(int c[][2],int n,int buff[][2]);
	int a[100][2],b[100][2];
	int c[200][2]={0};
	int buff[100][2]={0};
	int na=0,nb=0;
	int nc=0;
	int k;
	na=myscanf(a);
	nb=myscanf(b);
	sort(a,na);
	sort(b,nb);
	nc=unite(a,na,b,nb,c);
	sort1(c,nc);
	k=search(c,nc,buff);
	for(int i=0;i<nc;i++)\
		printf("%d %d\n",c[i][0],c[i][1]);
	for(int i=0;i<k;i++)
		printf("(%d,%d)\n",buff[i][0],buff[i][1]);
}
int myscanf(int a[][2])
{
	int cnt=0;
	for(int i=0;;i++){
		scanf("%d %d",a[i],a[i]+1);//a[i]为第i行第一个元素的地址
		cnt++;
		if(*a[i]==0)break;
	}
	return cnt-1;//把含0的一行抛弃掉
}
void sort(int mat[][2],int n)
{
	int min=0;
	int t=0;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(mat[j][0]<mat[i][0])
				min=j;
		}
		if(min!=i){
			t=mat[min][0];
			mat[min][0]=mat[i][0];
			mat[i][0]=t;
			t=mat[min][1];
			mat[min][1]=mat[i][1];
			mat[i][1]=t;
		}
	}
}
int unite(int a[][2],int na,int b[][2],int nb,int c[][2])
{
	int bflag[100]={0};
	int k=0;
	int same=0;
	for(int i=0;i<na;i++){
		for(int j=0;j<nb;j++){
			if(a[i][0]==b[j][0]){
				bflag[j]=1;
				same++;
				a[i][1]=(a[i][1]+b[j][1])/2;
				break;
			}
		}
		c[i][0]=a[i][0];
		c[i][1]=a[i][1];
	}
	for(int i=0;i<nb;i++){
		if(bflag[i]!=1){
			c[na+k][0]=b[i][0];
			c[na+k][1]=b[i][1];
			k++;
		}
	}
	return (na+nb-same);
}
void sort1(int c[][2],int n)
{
	int t=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(c[j][0]>c[j+1][0]){
				t=c[j][0];
				c[j][0]=c[j+1][0];
				c[j+1][0]=t;
				t=c[j][1];
				c[j][1]=c[j+1][1];
				c[j+1][1]=t;
			}
}
int search(int c[][2],int n,int buff[][2])
{
	int max=0;
	int k=0;
	for(int i=0;i<n;i++)
		if(c[i][1]>max)
			max=c[i][1];
	for(int i=0;i<n;i++){
		if(c[i][1]==max){
			buff[k][0]=c[i][0];
			buff[k][1]=c[i][1];
			k++;
		}
	}
	return k;
}