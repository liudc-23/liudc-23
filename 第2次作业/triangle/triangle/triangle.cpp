#include<stdio.h>
#include<math.h>
int main()
{int a,b,c;
float cir,square,p;
scanf("%d %d %d",&a,&b,&c);
if(a+b>c&&b+c>a&&a+c>b)
{cir=a+b+c;
p=cir/2;
square=sqrt(p*(p-a)*(p-b)*(p-c));
printf("%.2f %.2f",cir,square);}
else printf("Error");
return 0;
}