#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int **InputArray(int *m,int *n){
	scanf("%d %d",m,n);
	int **arr=(int**)malloc((*m)*sizeof(int*));
	for(int i=0;i<*m;i++)
		arr[i]=(int*)malloc((*n)*sizeof(int));
	for(int i=0;i<*m;i++)
		for(int j=0;j<*n;j++)
			scanf("%d",&arr[i][j]);
	return arr;
}
void ZeroArray(int m,int n,int **arr,int r){
	for(int i=r,j=0;j<n;j++){
		arr[i][j]=0;
	}
	for(int j=r,i=0;i<m;i++){
		arr[i][j]=0;
	}
}
int *FlattenArray(int m,int n,int **arr){
	int *vec=(int *)malloc(m*n*sizeof(int));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			vec[i*n+j]=arr[i][j];
		}
	}
	return vec;
}
int *SortArray(int m,int n,int **arr){
	int *vec=FlattenArray(m,n,arr);
	/*for(int i=0;i<m*n;i++)
		printf("%d ",vec[i]);
	printf("\n");*/
	int cnt=0;
	for(int i=0;i<m*n;i++){
		if(vec[i]==0){
			for(int k=i;k<m*n;k++){
				if(vec[k]!=0){
					int temp=vec[i];
					vec[i]=vec[k];
					vec[k]=temp;
				}
			}
		}
	}
	for(int i=0;i<m*n;i++)
		if(vec[i]==0)
			cnt++;
	for(int i=0;i<(m*n-cnt);i++){
		int min=vec[i];
		int mink=i;
		for(int k=i;k<(m*n-cnt);k++){
			if(vec[k]<min){
				min=vec[k];
				mink=k;
			}
		}
		if(mink!=i){
			int temp=vec[mink];
			vec[mink]=vec[i];
			vec[i]=temp;
		}
	}
	return vec;
}
void PrintArray(int m,int n,int **arr){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int m,n;
	int **arr=InputArray(&m,&n);
	int r=0;
	scanf("%d",&r);
	ZeroArray(m,n,arr,r);
	PrintArray(m,n,arr);
	int *vec=SortArray(m,n,arr);
	for(int i=0;i<m*n;i++){
		printf("%d ",vec[i]);
	}
	printf("\n");
	free(vec);
	for(int i=0;i<m;i++)
		free(arr[i]);
	free(arr);
	return 0;
}