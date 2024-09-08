#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct S{
	int id;
	char gender[7];
}staff;
typedef struct L{
	staff data;
	struct L* next;
}Node,*link;
void exchange(link L,int n1,int n2){
	link p1=L->next,p2=L->next;
	link pre1=L,pre2=L;
	if(n1==n2){
		return;
	}
	for(int n=n1;n>1;n--){
		pre1=pre1->next;
		p1=p1->next;
	}
	for(int n=n2;n>1;n--){
		pre2=pre2->next;
		p2=p2->next;
	}
	if((n2-n1==1)||(n2-n1==-1)){
		pre1->next=p2;
		link t=p2->next;
		p2->next=p1;
		p1->next=t;
	}
	else{
		link temp=p2->next;
		pre1->next=p2;
		p2->next=p1->next;//若节点相邻，这一步使得链表无限循环
		pre2->next=p1;
		p1->next=temp;
	}
	//这种交换逻辑在p1,p2相邻时产生问题
}
void sort(link L){
	link p=L;
	link q=L;
	link min;
	int np=1;
	int nq=0;
	int nmin=0;
	int N=0;
	while(p->next!=NULL){
		p=p->next;
		N++;
	}//求出总数
	while(np<=N){
		p=L;
		for(int n=np;n>0;n--)//交换节点后p会错乱，直接用整数相当于下标来访问
			p=p->next;
		min=p;
		nmin=np;
		q=p;
		nq=np;
		while(q->next!=NULL){
			q=q->next;
			nq++;
			if(q->data.id<min->data.id){
				min=q;
				nmin=nq;
			}
		}
		if(nmin!=np)
			exchange(L,np,nmin);
		np++;
	}
}
link Creatlist(){
	link L=(link)malloc(sizeof(Node));
	link p=L;
	int id=0;
	char gender[7];
	do{
		scanf("%d %s",&id,gender);
		if(id!=6666){
			link s=(link)malloc(sizeof(Node));
			s->data.id=id;
			strcpy(s->data.gender,gender);
			s->next=NULL;
			p->next=s;
			p=s;
		}
	}while(id!=6666);
	return L;
}
void Insert(link L,int n){//在第n个节点前插入一个节点
	link p=L->next;
	link pre=L;
	for(int n0=n;n0>1;n0--){
		pre=pre->next;
		p=p->next;
	}
	link s=(link)malloc(sizeof(Node));
	scanf("%d %s",&(s->data.id),s->data.gender);
	pre->next=s;
	s->next=p;
}
void Delete(link L,int n){//删除第n个节点
	link p=L->next;
	link pre=L;
	for(int n0=n-1;n0>0;n0--){
		p=p->next;
		pre=pre->next;
	}
	pre->next=p->next;
	free(p);
}
void OutputList(link L){
	link p=L->next;
	while(p!=NULL){
		printf("ID:%d ",p->data.id);
		printf("Gender:%s\n",p->data.gender);
		p=p->next;
	}
}
void DestoryList(link *L){
	link p=(*L)->next;
	link q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}
int main(){
	link L=Creatlist();
	OutputList(L);
	sort(L);
	printf("sorted:\n");
	OutputList(L);
	printf("insert:\n");
	int n=0;
	scanf("%d",&n);
	Insert(L,n);
	OutputList(L);
	int m=0;
	printf("delete:\n");
	scanf("%d",&m);
	Delete(L,m);
	OutputList(L);
	DestoryList(&L);
	return 0;
}
