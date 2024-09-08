#include<stdio.h>
void shift_2d_matrix(int m,int n,int *a[101],int *num)//注意a为指针数组
{
	int *p1=&a[0][0];
	int **p2=0;
	num[0]=num[0]%n;
	if(num[0]<0)
		num[0]=num[0]+n;
	num[1]=num[1]%m;
	if(num[1]<0)
		num[1]=num[1]+m;
	for(int k=0;k<m;k++){//对m行这么做
		p1=&a[k][n-1];//p1取到的直接是sort元素的地址
		for(int j=0;j<num[0];j++){//右移一位重复num[0]次
			for(int i=0;i<n;i++){
				*(p1+1)=*p1;
				p1--;
			}//右移一位
			a[k][0]=a[k][n];
			p1=&a[k][n-1];
		}
	}
	p2=a+m-1;//p2取到的是a数组里面存的指针，没有对sort直接改动
	for(int j=0;j<num[1];j++){//整行的地址改动
			for(int i=0;i<m;i++){
				*(p2+1)=*p2;
				p2--;
			}
			a[0]=a[m];
			p2=a+m-1;
	}
	return;
}
int main()
{
	void shift_2d_matrix(int m,int n,int *a[101],int *num);
	int m=0,n=0;
	int num[2]={0};
	int *a[101]={0};
	int sort[101][101];
	scanf("%d%d",&m,&n);
	if(m>0&&m<100&&n>0&&n<100){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&sort[i][j]);
		scanf("%d%d",&num[0],&num[1]);
		for(int i=0;i<101;i++)
			a[i]=sort[i];//让a对应sort的行
		shift_2d_matrix(m,n,a,num);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d",a[i][j]);//现在的a【i】里面是移位后的sort的行地址
				if(j!=n-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	else
		printf("ERROR");
	return 0;
}
