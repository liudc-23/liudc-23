#include<stdio.h>
#include<string.h>
void Input(int A[][2],int B[][2],int *m,int *n){
	int i=0;
	scanf("%d",m);
	for(i=0;i<*m;i++){
		scanf("%d %d",&A[i][0],&A[i][1]);
	}
	scanf("%d",n);
	for(i=0;i<*n;i++){
		scanf("%d %d",&B[i][0],&B[i][1]);
	}
}
void Print(int A[][2],int m){
	int i=0;
	for(i=0;i<m;i++){
		printf("%d",A[i][0]);
	}
	printf("\n");
	for(i=0;i<m;i++){
		printf("%d",A[i][1]);
	}
}
int Combine(int A[][2],int m,int B[][2],int n,int C[][2]){
	int i=0;
	int j=0;
	int sameflag[100]={0};
	int cnt=0;
	for(i=0;i<m;i++){
		cnt++;
		C[i][0]=A[i][0];
		C[i][1]=A[i][1];
		for(j=0;j<n;j++){
			if(B[j][0]==A[i][0])
				sameflag[j]=1;
				C[i][1]=((A[i][1]+B[i][1])/2);
		}
	}
	for(j=0;j<n;j++){
		if(sameflag[j]==0){
			cnt++;
			C[m+j][0]=B[j][0];
			C[m+j][1]=B[j][1];
		}
	}
	return cnt;
}
int main(){
	int m,n;
	int A[100][2],B[100][2];
	int C[100][2];
	int len=0;
	Input(A,B,&m,&n);
	len=Combine(A,m,B,n,C);
	Print(C,m);
}