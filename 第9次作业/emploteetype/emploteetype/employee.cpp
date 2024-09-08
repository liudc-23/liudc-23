#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
private:
	char name[100],place[100],city[100],post[100];
public:
	Employee(const char* n, const char* a, const char* c, const char* p){
		strcpy(name,n);
		strcpy(city, a);
        strcpy(place, c);
        strcpy(post, p);
	}
	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"City: "<<city<<endl;
		cout<<"Address: "<<place<<endl;
		cout<<"Postcode: "<<post<<endl;
	}
	void changename(const char *name1){
		strcpy(name,name1);
	}
};
int main()
{
	char name[100],city[100],place[100],post[100];
	cin.getline(name,100);
	cin.getline(city,100);
	cin.getline(place,100);
	cin.getline(post,100);
	char name1[100];
	cin.getline(name1,100);
	Employee em1(name,city,place,post);
	em1.display();
	em1.changename(name1);
	em1.display();
	return 0;
}