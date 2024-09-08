#include<stdio.h>

int main()
{double a1,b1,a2,b2;
scanf("%lf%lfi %lf%lfi",&a1,&b1,&a2,&b2);
printf("%.3lf%+.3lfi",a1*a2-b1*b2,a1*b2+b1*a2);
return 0;

}