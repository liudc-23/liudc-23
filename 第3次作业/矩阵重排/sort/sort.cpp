#include<stdio.h>
int main()
{int m,n,i,j,k;
int temp;
int sort[20][20];
int sum[20]={0};
scanf("%d %d",&m,&n);
if(m>0&&n>0&&m<=20&&n<=20)
{for(j=0;j<m;j++)
	for(i=0;i<n;i++)
	scanf("%d",&sort[j][i]);
	//����
for(j=0;j<m;j++)
	for(k=0;k<n-1;k++)
		for(i=0;i<n-k-1;i++)
	if(sort[j][i]>sort[j][i+1]){
	temp=sort[j][i];
	sort[j][i]=sort[j][i+1];
	sort[j][i+1]=temp;
	}//��������
for(j=0;j<m;j++)
	for(i=0;i<n;i++)
	sum[j]=sort[j][i]+sum[j];//���
 
for(k=0;k<m-1;k++)
	for(j=0;j<m-k-1;j++)
		if(sum[j]>sum[j+1]){
			for(i=0;i<n;i++){
			temp=sort[j][i];
			sort[j][i]=sort[j+1][i];
			sort[j+1][i]=temp;}
			temp=sum[j+1];//sumҲҪ�����б任
			sum[j+1]=sum[j];
			sum[j]=temp;}
		//������

for(j=0;j<m;j++)
	{for(i=0;i<n;i++)printf("%d ",sort[j][i]);
		printf("\n");}//��ӡ���
}
else printf("error");
return 0;
}
