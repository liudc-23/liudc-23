#include<stdio.h>
int main()
{int number;
double price,discount,pay;

scanf("%d %lf",&number,&price);
discount=20*((int)(number*price)/100);
pay=number*price-discount;
printf("%.2lf %.2lf",discount,pay);

return 0;
}