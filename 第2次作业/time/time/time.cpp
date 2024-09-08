#include<stdio.h>
int main()
{int a1,a2,a3;
int b1,b2,b3;
int ca,cb;
int difference;
int c1,c2,c3;

scanf("%d:%d:%d",&a1,&a2,&a3);
scanf("%d:%d:%d",&b1,&b2,&b3);
ca=a1*3600+a2*60+a3;
cb=b1*3600+b2*60+b3;
if(ca>=cb)
difference=ca-cb;
else difference=cb-ca;
c1=difference/3600;
c2=(difference-3600*c1)/60;
c3=difference-3600*c1-60*c2;
printf("%02d:%02d:%02d",c1,c2,c3);

return 0;
}