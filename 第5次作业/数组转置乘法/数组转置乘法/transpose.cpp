#include<stdio.h>
int main()
{
	void transpose(int p,int q,int *mat[100]);
	void multiply(int m,int n,int p,int q,int *a[100],int *b[100]);
	int a[100][100],b[100][100];
	int *ap[100],*bp[100];
	int m,n,p,q;
	scanf("%d %d",&m,&n);
	scanf("%d %d",&p,&q);
	if(((m>0&&m<100)&&(n>0&&n<100))&&((p>0&&p<100)&&(q>0&&q<100))){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<p;i++)
			for(int j=0;j<q;j++)
				scanf("%d",&b[i][j]);
		for(int i=0;i<100;i++)
			ap[i]=a[i];//用指针数组来访问二维数组
		for(int i=0;i<100;i++)
			bp[i]=b[i];
		transpose(p,q,bp);
		if(q==n){
			multiply(m,n,p,q,ap,bp);
			for(int i=0;i<m;i++){
				for(int j=0;j<p;j++){
					printf("%d",a[i][j]);
					if(j!=p-1)printf(" ");
				}
				printf("\n");
			}
		}
		else
			printf("INVALID");
	}
	else
		printf("ERROR");
}
void transpose(int p,int q,int *mat[100])
{
	int temp[100][100]={0};
	for(int i=0;i<p;i++)
		for(int j=0;j<q;j++)
			temp[j][i]=mat[i][j];
	for(int i=0;i<q;i++)
		for(int j=0;j<p;j++)
			mat[i][j]=temp[i][j];
	for(int i=0;i<q;i++){
		for(int j=0;j<p;j++){
			printf("%d",mat[i][j]);
			if(j!=p-1)printf(" ");
		}
		printf("\n");
	}
	return;
}
void multiply(int m,int n,int p,int q,int *a[100],int *b[100])
{
	int res[100][100]={0};
	int sum=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<p;j++){
			for(int k=0;k<n;k++)
				sum+=a[i][k]*b[k][j];
			res[i][j]=sum;
			sum=0;
		}
	for(int i=0;i<m;i++)
		for(int j=0;j<p;j++)
			a[i][j]=res[i][j];//存在a里面达到返回res的目的
	return;
}