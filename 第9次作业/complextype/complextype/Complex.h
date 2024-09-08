#ifndef COMPLEX
#define COMPLEX
#include<iostream>
#include<stdio.h>
using namespace std;
class Complex{
private:
	float a,b;
public:
	Complex(float a,float b=0):a(a),b(b){}
	//Complex(int a,int b=0):a(a),b(b){}
	void operator+(const Complex& ano){
		a+=ano.a;
		b+=ano.b;
	}
	void operator=(float aa){
		a=aa;
		b=0;
	}
	void add(const Complex& ano){
		a+=ano.a;
		b+=ano.b;
	}
	void show(){
		printf("%.2f %+.2fi",a,b);
	}
};
#endif

