// PROBLEM :: GENERATION RANDOM NUMBER IN LINK LIST.

// TIP : LEARN IT
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*arbit;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	n->arbit=NULL;
	return n;
}

void display(node*head)
{
	if(!head)
	{
		cout<<"list is empty \n";
		return;
	}
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

void randGen(node*head)
{
	if(head==NULL)return ;

	srand(time(NULL));

	int result=head->data;
	node*curr=head;

	for(int i=2;curr!=NULL;i++)
	{
		if(rand()%i == 0)
			result=curr->data;
		curr=curr->next;
	}

	cout<<result<<" ";

}
int main()
{
	node*head=newnode(10);
	head->next=newnode(40);
	head->next->next=newnode(53);
	head->next->next->next=newnode(30);
	head->next->next->next->next=newnode(67);
	head->next->next->next->next->next=newnode(12);
	head->next->next->next->next->next->next=newnode(89);

	randGen(head);
}

