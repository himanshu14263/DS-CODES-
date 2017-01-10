// PROBLEM :: compare two string represented as ll

#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node*next;
};

node*newnode(char data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<"   ";
	display(head->next);
}


// A RECURSIVE SOLUTION FOR THE PROBLEM
int compare(node*l1,node*l2)
{
	if(l1==NULL && l2==NULL)return 0;
	if(l1==NULL)return -1;
	if(l2==NULL)return 1;

	if(l1->data<l2->data)
		return -1;
	if(l1->data>l2->data)
		return 1;

	return (compare(l1->next,l2->next));

}
int main()
{
	node*head=newnode('a');
	head->next=newnode('z');
	head->next->next=newnode('c');
	head->next->next->next=newnode('k');


	node*head2=newnode('a');
	head2->next=newnode('b');
	head2->next->next=newnode('c');
	head2->next->next->next=newnode('k');


	display(head);
	cout<<"\n";
	display(head2);
	cout<<"\n\n";
	cout<<"answer is :: ";
	cout<<compare(head,head2);
}

