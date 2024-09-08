#include<stdio.h>
typedef struct D
{
	int year;
	int month;
	int day;
}date;
int sumdays(date a);
int isrun(int year);
int div(date a,date b);
int main()
{
	date a,b;
	scanf("%d %d %d",&a.year,&a.month,&a.day);
	scanf("%d %d %d",&b.year,&b.month,&b.day);
	printf("%d",div(a,b));
	return 0;
}
int isrun(int year)
{
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return 1;
			}
			else return 0;
		}
		return 1;
	}
	else
		return 0;
}
int div(date a,date b)//从2000年开始算起
{
	long int daysA,daysB;
	int div;
	daysA=sumdays(a);
	daysB=sumdays(b);
	div=daysA>daysB?(daysA-daysB):(daysB-daysA);
	return div;
}
int sumdays(date a)
{
	long int days=0;
	int j=1;
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int monrun[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	for(int i=1500;i<a.year;i++){
		if(isrun(i))
			days+=366;
		else
			days+=365;
	}
	while(j<a.month){
		if(isrun(a.year))
			days+=monrun[j-1];
		else
			days+=mon[j-1];
		j++;
	}
	days+=a.day;
	return days;
}
