#ifndef _PERSON_H_
#define _PERSON_H_
#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
class Person{
private:
	int height;
	float weight;
public:
	Person(){}
	Person(const int&height,const float&weight):height(height),weight(weight){}
	void showInfo(){
		printf("%d,%.2f",height,weight);
	}
};
#endif