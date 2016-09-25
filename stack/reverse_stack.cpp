#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};
typedef struct node node;
void push(node**stktop,int data)
{
	node*n=new node;
	if(n==NULL)
	{
		cout<<"over flow \n";
		return;
	}
	n->data=data;
	n->next=(*stktop);
	(*stktop)=n;
}
int pop(node**stktop)
{
	node*t=(*stktop);
	if((*stktop)==NULL)
	{
		cout<<"underflow \n";
		exit(0);
	}
	int temp=(*stktop)->data;
	(*stktop)=(t)->next;
	free(t);

	return temp;
}
int peek(node**stktop)
{
		int temp=(*stktop)->data;
		return temp;
}
bool isempty(node**s)
{
	if((*s)==NULL)
		return 1;
	return 0;
}
void disp(node**stktop)
{
	node*temp=(*stktop);
	while(temp!=NULL)
	{
		cout<<(temp)->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
void initstk(node**s)
{
	(*s)=NULL;
}
void sortedinsert(node**s,int x)
{
	if(isempty(s) || (x>peek(s)))
	{
		push(s,x);
		return;
	}

	int temp=pop(s);
	sortedinsert(s,x);
	push(s,temp);
}
void stksort(node**s)
{
	if(!isempty(s))
	{
		int temp=pop(s);
		stksort(s);
		sortedinsert(s,temp);
	}
}
int main()
{
	node*stktop;
	initstk(&stktop);
	push(&stktop,4);
	push(&stktop,3);
	push(&stktop,2);
	push(&stktop,1);
	disp(&stktop);
	//cout<<peek(&stktop);
	stksort(&stktop);
	disp(&stktop);

}
