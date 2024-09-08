#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Date{
private:
	char year[5],month[3],day[3];
	char buffer[20];
public:
	void show(){
		printf("%s-%s-%s\n",year,month,day);
	}
	void getdate(){
		char buffer[11];
		scanf("%s",buffer);
		strcpy(year,strtok(buffer,"-"));
		strcpy(month,strtok(NULL,"-"));
		strcpy(day,strtok(NULL,"-"));
	}
	char *catdate(){
		strcpy(buffer,year);//buffer本身不是一个字符串，要先拷贝
		strcat(buffer,month);
		strcat(buffer,day);
		return buffer;
	}
};
class People{
private:
	char name[11];
	char number[7];
	char sex[7];
	Date birthday;
	char id[20];
public:
	void input()
	{
		cin>>name;
		cin>>number;
		cin>>sex;
		birthday.getdate();
		cin>>id;
	}
	void output(){
		char buf[9]={0};
		for(int i=0;i<8;i++){
			buf[i]=id[i+6];//生日的转存
		}
		if(strcmp(buf,birthday.catdate())!=0){
			cout<<"birthday mismatch!"<<endl;
		}
		cout<<"Name: "<<name<<endl;
		cout<<"Number: "<<number<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Birthday: ";
		birthday.show();
		cout<<"ID: "<<id<<endl;
	}
};
