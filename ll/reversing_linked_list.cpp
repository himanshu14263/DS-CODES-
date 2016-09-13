#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
typedef struct node node;
int main()
{
	/////////////////CREATING LINKED LIST///////////////////////////////
	node*head=NULL;
	for(int i=0;i<6;i++)
	{
		int x;
		cout<<"enter the data for the node\n";
		cin>>x;
		node*n=new node;
		node*temp;
		n->next=NULL;
		n->data=x;
		if(head==NULL)
			temp=head=n;
		else
		{
			temp->next=n;
			temp=n;
		}
	}
    /////////////////////DISPLAY 1 /////////////////////////////////////
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}

	////////////////// REVERSING LINKED LIST /////////////////////////////
	node*prev,*curr;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;

	}
	head=prev;


	cout<<"\n";
	////////////////// DISPLAY 2 ////////////////////////////////////
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}

}
