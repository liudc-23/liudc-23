#include<stdio.h>
#include<string.h>
void input(int *m,int *n,int a[][100]);
void Computer(int buf[][100],int a[][100],int m,int n);
void Matrixsort(int a[][100],int buf[][100],int m,int n);
void print(int m,int n,int a[][100]);
int main()
{
	int m,n;
	int a[100][100]={0};
	input(&m,&n,a);
	int buf[100][100];
	Computer(buf,a,m,n);
	Matrixsort(a,buf,m,n);
	print(m,n,a);
	return 0;
}
void input(int *m,int *n,int a[][100]){
	scanf("%d %d",m,n);
	for(int i=1;i<*m+1;i++){
		for(int j=1;j<*n+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void Computer(int buf[][100],int a[][100],int m,int n){//a和buf矩阵都从1开始访问，边界元素全部置为0
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			//if(i!=0&&j!=0){
				buf[i][j]=a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1];
			/*
			else if(i==0&&j!=0){
				buf[i][j]=a[i+1][j]+a[i][j+1]+a[i][j-1];
			}
			else if(j==0&&i!=0){
				buf[i][j]=a[i][j+1]+a[i-1][j]+a[i+1][j];
			}
			else
				buf[i][j]=a[i][j+1]+a[i+1][j];*/
		}
	}
}
void print(int m,int n,int a[][100]){
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
}
void Matrixsort(int a[][100],int buf[][100],int m,int n){
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			int max=buf[i][j];
			int maxk=i,maxp=j;
			/*for(int k=i;k<=m;k++){
				for(int p=(k==i)?j:1;p<=n;p++){
					if(buf[k][p]>max){
						max=buf[k][p];
						maxk=k;
						maxp=p;
					}
				}
			}*/
			int p=j;
			for(int k=i;k<=m;){
				if(buf[k][p]>max){
					max=buf[k][p];
					maxk=k;
					maxp=p;
				}
				p++;
				if(p>m){
					p=1;
					k++;
				}
			}
			if(max!=buf[i][j]){//对应关系的排序两个都要交换
				int temp=a[i][j];
				a[i][j]=a[maxk][maxp];
				a[maxk][maxp]=temp;
				temp=buf[i][j];
				buf[i][j]=buf[maxk][maxp];
				buf[maxk][maxp]=temp;
			}
		}
	}
}