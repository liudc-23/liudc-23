#include<stdio.h>
int main()
{int n,j,i,temp,k=0;
int a[5][20]={0};
int b[100]={0};
	scanf("%d",&n);
for(j=0;j<n;j++)
	for(i=0;i<20;i++)
	{       scanf("%d",&temp);
			if(temp==0)break;
		a[j][i]=temp;
		scanf(",");
	}
for(j=0;j<n;j++)
	for(i=0;i<20;i++)
		if(a[j][i]!=0){
			b[k]=a[j][i];
			k++;
		}else break;
for(j=0;j<k-1;j++)
	for(i=0;i<k-j-1;i++)
		if(b[i]>b[i+1]) 
		{temp=b[i];
		 b[i]=b[i+1];
		 b[i+1]=temp;}
	printf("%d",b[0]);	
for(i=1;i<k;i++)printf(",%d",b[i]);
return 0;
}