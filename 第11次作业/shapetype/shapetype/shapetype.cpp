#include"shape.h"
#include<stdio.h>
int main(){
	Rectangle a(4,5);
	Circle b(3);
	printf("%f %f %f %f",a.getArea(),a.getPerim(),b.getArea(),b.getPerim());
}