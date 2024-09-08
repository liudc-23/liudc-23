#include<stdio.h>
int left(int a)
{
	int max,min,left;
	int b[4]={0};
	int temp=0;
		for(int i=0;i<4;i++){
			b[i]=a%10;
			a=a/10;
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3-i;j++)
				if(b[j]>b[j+1]){
					temp=b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}
		min=b[0]*1000+b[1]*100+b[2]*10+b[3];
		max=b[3]*1000+b[2]*100+b[1]*10+b[0];
		left=max-min;
		printf("(%d,%d,%d)\n",max,min,left);
		return left;
}
int main()
{int left(int a);
int a,a1=0,a2=0;
scanf("%d",&a);
if(a%1111!=0)
	for(;;){
		a1=left(a);
		if(a1==6174)break;
		a=a1;
	}
else printf("ERROR");
return 0;
}



		
			


