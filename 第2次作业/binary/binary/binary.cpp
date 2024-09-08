#include <stdio.h>
int main()
{int a,n=0,b;
scanf("%d",&a);
while(a>0){
	b=a%2;
	if(b==1)n++;
	a=a/2;}
	printf("%d",n);
	return 0;
}