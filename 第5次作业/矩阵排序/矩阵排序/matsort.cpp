#include<stdio.h>
void order(int m,int n,int *mat)
{
	int sum[100]={0};
	int temp=0;
	for(int k=0;k<n;k++)
		for(int j=0;j<m-1;j++)
			for(int i=0;i<m-1-j;i++)
				if(mat[k+i*100]>mat[k+(i+1)*100]){      //一列中的相邻两行元素相差100
					temp=mat[k+i*100];
					mat[k+i*100]=mat[k+(i+1)*100];
					mat[k+(i+1)*100]=temp;
					temp=0;
				}//列内部的排序
	for(int k=0;k<n;k++){
		for(int i=0;i<m;i++)
			sum[k]+=mat[k+i*100];
	}
	for(int j=0;j<n-1;j++){
		for(int k=0;k<n-1-j;k++){
			if(sum[k]>sum[k+1]){
				temp=sum[k];
				sum[k]=sum[k+1];
				sum[k+1]=temp;
				temp=0;
				for(int i=0;i<m;i++){    //把m行的元素全部交换
					temp=mat[i*100+k];   //第i行k列的位置为i*100+k
					mat[i*100+k]=mat[i*100+k+1];
					mat[i*100+k+1]=temp;
				}
			}
		}
	}
}
int main()
{
	void order(int m,int n,int *mat);
	int m,n;
	int mat[100000]={0};
	scanf("%d %d",&m,&n);
	if(m>0&&m<100&&n>0&&n<100){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mat[i*100+j]);
		order(m,n,mat);
		for(int i=0;i<m;i++){
			printf("%d",mat[i*100+0]);
			for(int j=1;j<n;j++)
				printf(" %d",mat[i*100+j]);
			printf("\n");
		}
	}
	else
		printf("ERROR");
	return 0;

}
//二维数组实现
/*#include<stdio.h>
#include<string.h>
int sum(int mat[][100],int j,int m);
void order(int m,int n,int mat[][100]){
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			int min=mat[i][j];
			int mink=i;
			for(int k=i;k<m;k++){
				if(mat[k][j]<min){
					min=mat[k][j];
					mink=k;
				}
			}
			if(min!=mat[i][j]){
				int temp=mat[i][j];
				mat[i][j]=mat[mink][j];
				mat[mink][j]=temp;
			}
		}
	}
	int sumed[100];
	for(int j=0;j<n;j++){
		sumed[j]=sum(mat,j,m);
	}
	for(int j=0;j<n;j++){
		int summin=sumed[j];
		int summink=j;
		for(int k=j;k<n;k++){
			if(sumed[k]<summin){
				summin=sumed[k];
				summink=k;
			}
		}
		if(summink!=j){
			for(int i=0;i<m;i++){
				int temp=mat[i][j];
				mat[i][j]=mat[i][summink];
				mat[i][summink]=temp;
			}
			int temp=sumed[j];
			sumed[j]=sumed[summink];
			sumed[summink]=temp;
		}
	}	
}
int sum(int mat[][100],int j,int m){
	int sum=0;
	for(int i=0;i<m;i++){
		sum+=mat[i][j];
	}
	return sum;
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	if((m>0&&m<100)&&(n>0&&n<100)){
		int mat[100][100];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		order(m,n,mat);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("ERROR");
	return 0;
}*/