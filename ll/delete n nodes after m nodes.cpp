
// PROBLEM :: DELETE N NODES AFTER M NODES OF LINK LIST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}
void deleteNafterM(node*head,int m,int n)
{
	node*curr=head;
	while(curr)
	{
		int i=1;
		while(i<m && curr)
		{
			curr=curr->next;
			i++;
		}

		if(curr==NULL)return;

		node*temp=curr->next;

		int j=1;
		while(j<=n && temp)
		{
			node*t=temp;
			temp=temp->next;
			j++;
			free(t);
		}

		curr->next=temp;
		curr=temp;
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);

	int n,m;
	cout<<"enter the value of m and n\n";

	cin>>m>>n;

	display(head);
	cout<<"\n";
	deleteNafterM(head,m,n);
	display(head);
}

