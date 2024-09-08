#include<stdio.h>
#include<string.h>
typedef struct S
{
	char name[32];
	char num[32];
	char pal[32];
	char age[32];
	char gender[32];
}stu;
void input(stu *a);
void output(stu *a);
void search(stu student[],char *target);
int N;
int main()
{
	stu student[128];
	char tar[100][160];
	int i=-1;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		input(&student[i]);
	do{
		i++;
		gets(tar[i]);
	}while(!(tar[i][0]=='q'&&tar[i][1]=='u'&&tar[i][2]=='i'&&tar[i][3]=='t'));
	for(int i=0;i<N;i++)
		output(&student[i]);
	for(int j=0;j<i;j++){//i为查找次数
		search(student,tar[j]);
	}
	return 0;
}
void input(stu *a)
{
	char *p;
	scanf("%s",a->name);
	p=a->name+strlen(a->name);
	*p=' ';//加一个空格再接着输入
	scanf("%s",p+1);
	p=a->name+strlen(a->name);
	*(p-1)='\0';//删除逗号
	scanf("%s",a->num);
	p=a->num+strlen(a->num);
	*(p-1)='\0';
	scanf("%s",a->pal);
	p=a->pal+strlen(a->pal);
	*(p-1)='\0';
	scanf("%s",&(a->age));
	p=a->age+strlen(a->age);
	*(p-1)='\0';
	scanf("%s\n",a->gender);//加一个换行，防止gets读入换行符
}
void output(stu *a)
{
	printf("%s, %s, %s, %s, %s\n",a->name,a->num,a->pal,a->age,a->gender);
}
void search(stu student[],char *target)//解决了多个问题：查找条件多个和要求符合条件的只有一个
{
	int flag=0,flagall=0;
	int n=0;//记录一次查找中条件个数
	char *toked_tar[5];
	int cnt=0;//记录满足条件的人数
	int outputplace=0;//记录要打印的位置
	toked_tar[0]=strtok(target,",");
	while(toked_tar[n]!=NULL){
		n++;
		toked_tar[n]=strtok(NULL,",");
	}//按照逗号分割开
	for(int i=0;i<N;i++){
		for(int j=0;j<n;j++){
			if(strcmp(student[i].name,toked_tar[j])==0)	flag++;
			if(strcmp(student[i].num,toked_tar[j])==0)	flag++;
			if(strcmp(student[i].pal,toked_tar[j])==0)	flag++;
			if(strcmp(student[i].gender,toked_tar[j])==0)	flag++;
			if(strcmp(student[i].age,toked_tar[j])==0)	flag++;
		}
		if(flag==n){
			flagall=1;
			cnt++;
			outputplace=i;
		}
		flag=0;
	}
	if(flagall=1&&cnt==1)//找到且只找到一个
		output(&student[outputplace]);
	else
		printf("error\n");
}