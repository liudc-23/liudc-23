#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int num;
	struct S *next;
}stu,*link;
void makelist(link *L,int N);
void destory(link *L,int N);
int main()
{
	int N,m;
	int cnt=0;
	link L;
	link p,q;
	scanf("%d %d",&N,&m);
	makelist(&L,N);
	/*p=L->next;
	for(int i=0;i<N+1;i++){
		printf("%d\n",p->num);
			p=p->next;
	}*/
	q=L;
	p=q->next;
	if(m==1){ 
		printf("%d",N);//m为1时删除第一个节点后循环断裂，不能访问头节点的数据域
		destory(&L,N);
	}
	else{
		while(1){
			cnt++;
			if(cnt==m){//删除节点
				q->next=p->next;
				free(p);
				p=q->next;
				cnt=0;
			}
			else{//注意删除节点后不需要再移动指针，只有没删除时才移动
				q=p;
				p=p->next;
			}//注意：只剩一个节点时p->next是迷途指针
			if(p->next==q) break;//剩两个节点时退出
		}
		if(m%2==0)
			printf("%d",p->num);
		else
			printf("%d",q->num);
		free(p);
		free(q);
	}
	return 0;
}
void makelist(link *L,int N)
{
	link p,s;
	(*L)=(link)malloc(sizeof(stu));
	p=(*L);
	p->next=NULL;
	for(int i=1;i<=N;i++){
		s=(link)malloc(sizeof(stu));
		s->num=i;
		p->next=s;
		p=s;
	}
	p->next=(*L)->next;//循环链表
}
void destory(link *L,int N)
{
	link p=*L;
	link q;
	for(int i=0;i<N;i++){
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}