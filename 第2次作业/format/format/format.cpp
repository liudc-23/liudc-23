#include<stdio.h>
int main()
{float a,b,c,d,e,f,g,h,i,j,k,l;
int a1,b1,c1,d1,e1,f1;
scanf("%f%f%f%f%f%f%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l);
a1=a*1000;
b1=b*1000;
c1=c*1000;
d1=d*1000;
e1=e*1000;
f1=f*1000;
a=a1/1000.0;
b=b1/1000.0;
c=c1/1000.0;
d=d1/1000.0;
e=e1/1000.0;
f=f1/1000.0;

printf("%-6.3f %-6.3f\n%-6.3f %-6.3f\n%-6.3f %-6.3f\n",a,b,c,d,e,f);
printf("%6.2f %6.2f %6.2f\n%6.2f %6.2f %6.2f",g,h,i,j,k,l);
return 0;
}
