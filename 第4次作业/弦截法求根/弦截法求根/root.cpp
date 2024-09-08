#include<stdio.h>
#include<math.h>
float f(float x);
float xpoint(float x1,float x2);
float root(float x1,float x2);
float a,b,c,d,e;
int main()
{
	float x1,x2,x0;
	scanf("%f,%f,%f,%f,%f",&a,&b,&c,&d,&e);
	scanf("%f,%f",&x1,&x2);
	x0=root(x1,x2);
	printf("%.3f",x0);
	return 0;
}
float f(float x)//求出函数值
{float result;
result=pow(x,5)+a*pow(x,4)+b*pow(x,3)+c*pow(x,2)+d*x+e;
return result;
}
float xpoint(float x1,float x2)//求出函数上两点间连线与x轴的交点
{float x;
x=(f(x1)*x2-f(x2)*x1)/(f(x1)-f(x2));
return x;
}
float root(float x1,float x2)//用连线交点逼近根
{float x01,x02,y1=f(x1);
do{
	x01=xpoint(x1,x2);
if(f(x01)*y1>0){
	x1=x01;
	y1=f(x01);
}
else x2=x01;
x02=xpoint(x1,x2);
if(f(x02)*y1>0){
	x1=x02;
	y1=f(x02);
}
else x2=x02;
}while(fabs(x02-x01)>=1e-6);//每次循环里面两次迭代方便判断步长
return x02;
}
