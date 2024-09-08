#include<stdio.h>
#include<math.h>
int m,n;
void input(float vectors[][100],int *m,int *n){
	scanf("%d %d",m,n);
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			scanf("%f",&vectors[i][j]);
		}
	}
}
float vectormod(float vec[100]){
	float sum=0;
	for(int i=0;i<n;i++){
		sum+=vec[i]*vec[i];
	}
	return sqrt(sum);
}
void Swapvect(float vec[][100],int i,int j){
	for(int k=0;k<n;k++){
		float temp=vec[i][k];
		vec[i][k]=vec[j][k];
		vec[j][k]=temp;
	}
}
void sortvec(float vec[][100]){
	float mod[100];
	for(int i=0;i<m;i++){
		mod[i]=vectormod(vec[i]);
	}
	for(int i=0;i<m;i++){
		float min=mod[i];
		int mink=i;
		for(int j=i;j<m;j++){
			if(mod[j]<min){
				min=mod[j];
				mink=j;
			}
		}
		if(mink!=i){
			Swapvect(vec,i,mink);
			float temp=mod[i];
			mod[i]=mod[mink];
			mod[mink]=temp;
		}
	}
}
int main(){
	float vec[100][100];
	input(vec,&m,&n);
	sortvec(vec);
	for(int i=0;i<m;i++)
		printf("%.2f\n",vectormod(vec[i]));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%.2f ",vec[i][j]);
		}
		printf("\n");
	}
}