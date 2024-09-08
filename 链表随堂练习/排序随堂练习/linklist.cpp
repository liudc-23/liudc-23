#include<stdio.h>
#include<stdlib.h>
typedef struct LN{
	int data;
	struct LN *next;
}Node,*link;
link Mycreate(){//创建链表
	link L=(link)malloc(sizeof(Node));
	L->next=NULL;
	link p=L,s;
	int val=1;
	while(1){
		scanf("%d",&val);
		s=(link)malloc(sizeof(Node));
		s->next=NULL;
		if(val!=0)
			s->data=val;
		else{
			free(s);
			s=NULL;
			break;
		}
		if(L->next!=NULL){//第二次输入才判断
			link q=L;
			int flag=0;
			while(q->next!=NULL){
				q=q->next;
				if(s->data==q->data)
					flag=1;
			}
			if(flag==1){
				free(s);
				printf("unvalid input\n");
				continue;
			}
		}
		p->next=s;
		p=s;
	}
	p->next=NULL;
	return L;
}
void Myfree(link *L){
	link p=(*L)->next;
	link q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}
void Myprint(link L){
	link p=L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
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
		for(int n=np;n>0;n--)
			p=p->next;
		min=p;
		nmin=np;
		q=p;
		nq=np;
		while(q->next!=NULL){
			q=q->next;
			nq++;
			if(q->data<min->data){
				min=q;
				nmin=nq;
			}
		}
		if(nmin!=np)
			exchange(L,np,nmin);
		np++;
	}
}
int main(){
	char flag=0;
	do{
		link L=Mycreate();
		Myprint(L);
		sort(L);
		Myprint(L);
		Myfree(&L);
		//getchar();
		fflush(stdin);//上一个回车会被读为字符
		printf("enter @ to exit, other to continue");
		scanf("%c",&flag);
	}while(flag!='@');
	return 0;
}