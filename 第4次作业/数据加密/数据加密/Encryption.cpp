#include<stdio.h>
#include<string.h>
void desame(char key[],char dkey[]);
void expand(char dkey[]);
int main()
{char key[30]={0};
char dkey[30]={0};
char input[1000]={0},secret[1000]={0};
scanf("%s",key);
scanf("%s",input);
desame(key,dkey);
expand(dkey);
for(int i=0;i<strlen(input);i++)
	secret[i]=dkey[input[i]-'A'];//input中的A对应着dkey中的第一个；地址存在对应关系
printf("%s",secret);

return 0;		
}
void desame(char key[],char dkey[])//把key中重复的字母去掉存在dkey中
{
	int k=1;
	int same=0;
		dkey[0]=key[0];
	for(int i=1;i<26;i++){
		same=0;
		for(int j=0;j<i;j++){
			if(key[i]==key[j]){
				same =1;
				break;
			}
		}
		if(same==0){
			dkey[k]=key[i];//找到不一样的才存入
			k++;
		}
	}
}

void expand(char dkey[])
{int len=strlen(dkey);
char ch[30];
int same=0;
int n=len;
	for(int i=0;i<26;i++)
		ch[i]='A'+i;
	for(int j=0;j<26;j++){
		same=0;
		for(int k=0;k<strlen(dkey);k++){
			if(ch[j]==dkey[k]){ 
				same=1;
				break;
			}//用来判断dkey有没有出现相同的
		}
		if(same==0){
			dkey[n]=ch[j];
			n++;
		}
	}
}

	



	





