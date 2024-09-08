#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class Client
{
private:
	static char ServerName[20];
	static int Clientnum;
public:
	static void ChangeServerName(){
		char newname[20];
		scanf("%s",newname);
		strcpy(ServerName,newname);
		cout<<"server name: "<<ServerName<<endl;
		cout<<"client number: "<<Clientnum<<endl;
	}
	Client(){
	cout<<"server name: "<<ServerName<<endl;
	cout<<"client number: "<<Clientnum<<endl;
	}
	static void changenum(int x){
		Clientnum+=x;
		cout<<"server name: "<<ServerName<<endl;
		cout<<"client number: "<<Clientnum<<endl;
	}
	void show(){
		cout<<"server name: "<<ServerName<<endl;
		cout<<"client number: "<<Clientnum<<endl;
	}
	static int getnum(){return Clientnum;}
	void setnum(int x){Clientnum=x;}
};
char Client::ServerName[20]={"Server1"};//静态成员定义和初始化
int Client::Clientnum=0;
int main()
{
	int n;
	cin>>n;
	int x;
	int y;
	char newname[20];
	Client cli;
	for(;n>0;n--){
		char order[10];
		int flag=0;
		cin>>order;
		if(strcmp(order,"rename")==0){
			Client::ChangeServerName();
		}
		if(strcmp(order,"add")==0){
			cin>>x;
			if(Client::getnum()+x>100000){//最大不超过100000
				cli.setnum(100000);
				cli.show();
			}
			else
				Client::changenum(x);
		}
		if(strcmp(order,"sub")==0){
			cin>>y;
			if((Client::getnum()-y)>0)//最小不小于0
				Client::changenum(-y);
			else
				Client::changenum(-(Client::getnum()));
		}
	}
	return 0;		
}