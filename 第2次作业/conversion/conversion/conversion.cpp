#include<stdio.h>
int main()
{int a,n,ret=0,p,x=1;
scanf("%d %d",&n,&a);
while(n!=0)
{p=n%a;
ret=ret+p*x;
x=x*10;//x记位的权
n=n/a;} 
printf("%d",ret);
return 0;
}