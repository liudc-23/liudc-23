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
	for(int j=0;j<i;j++){//iΪ���Ҵ���
		search(student,tar[j]);
	}
	return 0;
}
void input(stu *a)
{
	char *p;
	scanf("%s",a->name);
	p=a->name+strlen(a->name);
	*p=' ';//��һ���ո��ٽ�������
	scanf("%s",p+1);
	p=a->name+strlen(a->name);
	*(p-1)='\0';//ɾ������
	scanf("%s",a->num);
	p=a->num+strlen(a->num);
	*(p-1)='\0';
	scanf("%s",a->pal);
	p=a->pal+strlen(a->pal);
	*(p-1)='\0';
	scanf("%s",&(a->age));
	p=a->age+strlen(a->age);
	*(p-1)='\0';
	scanf("%s\n",a->gender);//��һ�����У���ֹgets���뻻�з�
}
void output(stu *a)
{
	printf("%s, %s, %s, %s, %s\n",a->name,a->num,a->pal,a->age,a->gender);
}
void search(stu student[],char *target)//����˶�����⣺�������������Ҫ�����������ֻ��һ��
{
	int flag=0,flagall=0;
	int n=0;//��¼һ�β�������������
	char *toked_tar[5];
	int cnt=0;//��¼��������������
	int outputplace=0;//��¼Ҫ��ӡ��λ��
	toked_tar[0]=strtok(target,",");
	while(toked_tar[n]!=NULL){
		n++;
		toked_tar[n]=strtok(NULL,",");
	}//���ն��ŷָ
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
	if(flagall=1&&cnt==1)//�ҵ���ֻ�ҵ�һ��
		output(&student[outputplace]);
	else
		printf("error\n");
}