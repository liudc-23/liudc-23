#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct S
{
	int no;
	char name[20];
	struct S *next;
	struct S *pre;
}stu,*link;
int makelist(link *L);
void destory(link *L);
int sort(link L,link s[]);
void equal(link a,link b);
int main()
{
	link L;
	link s[1000]={0};
	int tar=0;
	int flag=0;
	int n=makelist(&L);
	printf("%d\n",n);
	tar=sort(L,s);
	for(int i=1;i<n-1;i++){
		if(s[i]->no==tar){
			flag=1;
			printf("%d, %s\n%d, %s",
				s[i+1]->no,s[i+1]->name,s[i-1]->no,s[i-1]->name);
		}
	}
	if(s[0]->no==tar){
		flag=1;
		printf("%d, %s\n",s[1]->no,s[1]->name);
	}
	if(s[n-1]->no==tar){
		flag=1;
		printf("%d, %s\n",s[n-2]->no,s[n-2]->name);
	}
	if(flag==0)
		printf("ERROR");
	destory(&L);
	return 0;
}
int makelist(link *L)
{
	link p,s;
	int cnt=0;
	*L=(link)malloc(sizeof(stu));
	(*L)->pre=NULL;
	p=*L;
	while(1){
		s=(link)malloc(sizeof(stu));
		p->next=s;
		s->pre=p;
		if(scanf("%d,%s",&(s->no),s->name)==1){
			break;
		}
		p=s;
		cnt++;
	}
	s->next=NULL;
	return cnt;
}
void destory(link *L)
{
	link p=(*L);
	link q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}
int sort(link L,link s[])
{
	link p=L->next;
	link temp;
	int max;
	int i=0;
	for(i=0;p->next!=NULL;i++){//最后一个节点是查找对象
		s[i]=p;
		p=p->next;
	}//共有i个数据
	//现在的p指向最后一个节点
	for(int j=0;j<i-1;j++){
		max=j;
		for(int k=j+1;k<i;k++){
			if(s[k]->no>s[max]->no)
				max=k;
		}
		if(max!=j){
			temp=s[j];
			s[j]=s[max];
			s[max]=temp;
		}
	}
	for(int j=0;j<i;j++)
		printf("%d, %s\n",s[j]->no,s[j]->name);
	return p->no;
}
