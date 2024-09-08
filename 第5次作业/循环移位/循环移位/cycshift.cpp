#include<stdio.h>
int main()
{
	void shift_vetor(int m,int *vector,int number);
	int a[100]={0};
	int m;
	int num;
	scanf("%d",&m);
	if(m>0&&m<100){
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&num);
		shift_vetor(m,a,num);
	}
	else 
		printf("ERROR");
	return 0;
}
void shift_vetor(int m,int *vector,int number)
{
	int num=number%m;
	int i=0;
	int *a;
	int flag=0;//表示是否调转过
	if(num<0)
		num=m+num;//num为数据右移位次数
	a=vector;
	vector=vector+(m-num);
	for(int j=0;j<m;j++){
		if(m-num+i>=m&&flag==0){//右移总位数=m时超界
			vector=a;
			i=0;
			flag=1;
		}
		printf("%d",*(vector+i));
		if(j!=m-1)printf(" ");
		i++;
		
	}
}