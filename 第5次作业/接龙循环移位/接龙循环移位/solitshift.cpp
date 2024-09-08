#include<stdio.h>
int main()
{
	void shift(int m,int n,int *mat,int num);
	int m=0, n=0;
	int num=0;
	int mat[10000]={0};
	scanf("%d %d",&m,&n);
	if(m>0&&m<100&&n>0&&n<100){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mat[i*100+j]);
		scanf("%d",&num);
		shift(m,n,mat,num);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d",mat[i*100+j]);
				if(j!=n-1)printf(" ");
			}
			printf("\n");
		}
	}
	else
		printf("ERROR");
}
void shift(int m,int n,int *mat,int num)
{
	int last[100]={0},first[100]={0};
	int *p=0;
	num=num%(m*n);
	if(num<0)
		num=m*n+num;
	for(int k=0;k<num;k++){
		for(int i=0;i<m;i++){
			first[i]=mat[i*100];
			last[i]=mat[i*100+n-1];
		}//保留第一位和最后一位方便赋值
		for(int i=0;i<m;i++){
			if(i%2==0){//行标为偶数是右移
				p=(mat+i*100)+n-1;
				while(p!=mat+i*100){
					*p=*(p-1);
					p--;
				}
			}
			if(i%2==1){//行标为奇数左移
				p=(mat+i*100);
				while(p!=mat+i*100+n-1){
					*p=*(p+1);
					p++;
				}
			}
		}
		for(int i=0;i<m;i++){
			if(i==0){//首位特殊分类讨论
				if(m%2==1)
					mat[0]=last[m-1];
				else 
					mat[0]=first[m-1];
			}
			if(i%2==0&&i!=0)
				mat[i*100]=first[i-1];
			if(i%2==1)
				mat[i*100+n-1]=last[i-1];
		}
	}
}
