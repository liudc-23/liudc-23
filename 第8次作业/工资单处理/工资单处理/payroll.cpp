#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct S
{
	char no[11];
	char name[11];
	int salary;
	struct S *next;
}staff,*link;
void makelist(link *a,int n);
void destory(link *a);
void connect(link *a,link *b);
//void sort(link a,link sorted[],int type);
void printList(link a);
void sort_2(link a,link sorted[],int type);
int main()
{
	int n1,n2;
	link list1,list2;
	link sorted01[1000];
	link sorted02[1000];
	scanf("%d",&n1);
	makelist(&list1,n1);
	scanf("%d",&n2);
	makelist(&list2,n2);
	connect(&list1,&list2);
	sort_2(list1,sorted01,2);
	//printList(list1);
	for(int i=0;i<n1+n2;i++){
		printf("{%s, %s, %d}\n",sorted01[i]->no,sorted01[i]->name,sorted01[i]->salary);
	}
	printf("\n");
	//sort(list1,sorted02,2);
	sort_2(list1,sorted02,1);
	for(int i=0;i<n1+n2;i++){
		printf("{%s, %s, %d}\n",sorted02[i]->no,sorted02[i]->name,sorted02[i]->salary);
	}
	destory(&list1);
	return 0;
}
void makelist(link *a,int n)
{
	link p,s;
	p=(*a)=(link)malloc(sizeof(staff));
	p->next=NULL;
	for(int i=0;i<n;i++){
		s=(link)malloc(sizeof(staff));
		scanf("%s %s %d",s->no,s->name,&(s->salary));
		p->next=s;
		p=s;
	}
	p->next=NULL;
}
void destory(link *a)
{
	link p=*a,q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	(*a)=NULL;
}
void connect(link *a,link *b)
{
	link p=*a,q;
	while(p!=NULL){
		q=p;
		p=p->next;
	}//找到尾节点
	q->next=(*b)->next;
	free(*b);
	*b=NULL;//连接完毕后把第二个链表头节点置空
}
void sort(link a,link sorted[],int type)//使用指针数组进行链表排序/type表示排序标准不同
{
	link p=a->next;
	int i=0;
	int min=0;
	link temp=0;
	while(p!=NULL){
		sorted[i]=p;
		p=p->next;
		i++;
	}//共有i个数据
	for(int j=0;j<i-1;j++){
		min=j;
		for(int k=j+1;k<i;k++){
			if(type==1){
				if(strcmp(sorted[k]->no,sorted[j]->no)<0)
					min=k;
			}
			if(type==2){
				if((sorted[k]->salary)<(sorted[j]->salary))
					min=k;
			}
		}
		if(min!=j){
			temp=sorted[j];
			sorted[j]=sorted[min];
			sorted[min]=temp;
		}
	}
}
void printList(link a) {
    link p = a->next;
    while (p != NULL) {
        printf("{%s, %s, %d}\n", p->no, p->name, p->salary);
        p = p->next;
    }
}
void sort_2(link a,link sorted[],int type)
{
	link p=a->next;
	int i=0;
	link temp=0;
	while(p!=NULL){
		sorted[i]=p;
		p=p->next;
		i++;
	}//共有i个数据
	for(int j=0;j<i-1;j++){
		for(int k=0;k<i-j-1;k++){
			if(type==1){
				if(sorted[k]->salary>sorted[k+1]->salary){
					temp=sorted[k];
					sorted[k]=sorted[k+1];
					sorted[k+1]=temp;
				}
			}
			if(type==2){
				if(strcmp(sorted[k]->no,sorted[k+1]->no)>0){
					temp=sorted[k];
					sorted[k]=sorted[k+1];
					sorted[k+1]=temp;
				}
			}
		}
	}
}
