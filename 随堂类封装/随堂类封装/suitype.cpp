#include<stdio.h>
#include<iostream>
#include"Cuboid.h"
using namespace std;
int main(){
	int x1,y1;
	int x2,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	Point p1(x1,y1);
	Point p2(x2,y2);
	Rect r(p1,p2);
	int h;
	cin>>h;
	Cuboid cub(r,h);
	int newx,newh;
	cin>>newx>>newh;
	cub.changex(newx);
	cub.changeh(newh);
	printf("%.2f\n",p1.dist(p2));
	cout<<r.getArea()<<endl;
	cout<<cub.getVol()<<endl;
	cout<<cub.getCuArea()<<endl;
}