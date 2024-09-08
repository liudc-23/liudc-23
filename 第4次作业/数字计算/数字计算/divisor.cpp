#include<stdio.h>
int max(int a, int b, int c)
{int max=b;
if(a>b){
	if(a>c)max=a;
	else max=c;
}else if(c>b)max=c;
return max;
}

int div(int a,int b,int c)
{int m;
	for(int i=1;i<=max(a,b,c);i++)
		if(a%i==0&&b%i==0&&c%i==0)m=i;//从小到大找最后的是最大的
	return m;
}
int main()
{int p,q,r;
int a[1000]={0};
int n=0,temp=0,num=0;
for(int i=0;;i++){
	if(scanf("%d%d%d",&p,&q,&r)!=0)n++;
	if(p==0||q==0||r==0)break;
	if(p<0||q<0||r<0){printf("error\n");continue;}
	else a[i]=div(p,q,r);
}
for(int j=0;j<n-1;j++){
	for(int i=0;i<n-j-1;i++){
		if(a[i]<a[i+1]){//把小值放到后面的沉底排序
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
}
for(int j=0;j<n;j++)
	if(a[0]==a[j])num++;//a[0]是最大值
printf("%d %d",a[0],num);
return 0;
}
