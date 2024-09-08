#include<stdio.h>
int main()
{double sell,salary;
scanf("%lf",&sell);
if(sell<=8)salary=sell*62.5;
else 
salary=8*62.5+(sell-8)*62.5*1.5;
printf("%.2lf",salary);
return 0;}