#include<stdio.h>
#include<math.h>
int main()
{int way;
	double  b,p,temp;
scanf("%lf %d",&b,&way);
switch(way){
case 1:p=b*(1+0.055*5);break;
case 2:temp=b*(1+0.044*2);
	p=temp*(1+0.05*3);break;
case 3:temp=b*(1+0.05*3);
	p=temp*(1+0.044*2);break;
case 4:p=b*pow(1+0.035,5);break;
case 5:p=b*pow(1+0.005/4,20);break;
default: p=b;}
printf("%.2lf",p);
return 0;
}

