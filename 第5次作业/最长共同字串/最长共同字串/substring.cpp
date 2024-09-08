#include<stdio.h>
#include<string.h>
void toke(char*s1,char *buf[]);
int Longest_substring(char s1[],char s2[],char s3[],char *buffer){
	char *buf1[20]={0},*buf2[20]={0},*buf3[20]={0};
	toke(s1,buf1);
	toke(s2,buf2);
	toke(s3,buf3);
	int max=0;
	int flagsame[20]={0};
	for(int i=0;buf1[i]!=NULL;i++){
		int flag=0;
		for(int j=0;buf2[j]!=NULL;j++){
			if(strcmp(buf1[i],buf2[j])==0){
				for(int k=0;buf3[k]!=NULL;k++){
					if(strcmp(buf2[j],buf3[k])==0)
						flag=1;
				}
			}
		}
		if(flag){
			if(strlen(buf1[i])>max)
				max=strlen(buf1[i]);
			flagsame[i]=1;
		}
	}
	for(int i=0;buf1[i]!=NULL;i++){
		if(flagsame[i]==1&&strlen(buf1[i])==max){//两次遍历，保证输出的是最长字串
			strcpy(buffer,buf1[i]);
			buffer+=strlen(buf1[i]);
			*buffer=' ';
			buffer++;
		}
	}
	return max;
}
void toke(char*s1,char *buf[]){
	buf[0]=strtok(s1," ");
	for(int i=1;i<125;i++){
		buf[i]=strtok(NULL," ");
		if(buf[i]==NULL)
			break;
	}
}

int main(){
	char s1[256]={0},s2[256]={0},s3[256]={0};
	scanf("%[^\n]",s1);//%[^\n]表示以某个字符结尾;
	getchar();//防止上一次输入的回车符被下一行读取
	gets(s2);
	gets(s3);
	char buffer[256]={0};
	int m=Longest_substring(s1,s2,s3,buffer);
	if(m!=0)
		printf("%s%d",buffer,m);
	else
		printf("NULL");
	return 0;
}
		