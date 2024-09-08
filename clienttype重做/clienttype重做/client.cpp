#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Client{
private:
	static char Servername[20];
	static int num;
public:
	static void ChangeServerName(char *newname){
		strcpy(Servername,newname);
		cout<<"server name: "<<Servername<<endl;
		cout<<"client number: "<<num<<endl;
	}
	static void ChangeNum(int x){
		num+=x;
		if(num>100000)
			num=100000;
		if(num<0)
			num=0;
		cout<<"server name: "<<Servername<<endl;
		cout<<"client number: "<<num<<endl;
	}
	Client(){
		cout<<"server name: "<<Servername<<endl;
		cout<<"client number: "<<num<<endl;
	}
};
char Client::Servername[20]={"Server1"};
int Client::num=0;
int main(){
	int n;
	cin>>n;
	Client cl;
	for(;n>0;n--){
		char order[10];
		cin>>order;
		if(strcmp(order,"rename")==0){
			char newname[20];
			cin>>newname;
			Client::ChangeServerName(newname);
		}
		else if(strcmp(order,"add")==0){
			int x;
			cin>>x;
			Client::ChangeNum(x);
		}
		else if(strcmp(order,"sub")==0){
			int x;
			cin>>x;
			Client::ChangeNum(-x);
		}
		else 
			cout<<"ERROR";
	}
}

