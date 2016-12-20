
// PROBLEM :: SEARCHING AN ELEMENT(BOTH ITERATIVE AND RECURSIVE)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};
typedef struct node node;

node* newnode(int data)
{
	node* n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

// insert at front
void insertAtFront(node*& head,int data)
{
	node*n=newnode(data);

	if(head==NULL)
		head=n;
	else
	{
		n->next=head;
		head=n;
	}
}

// ITERATIVE METHOD
int findLength(node*head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head=head->next;
	}
	return c;
}

// RECURSIVE METHOD
int findLengthRecur(node*head)
{
	if(head==NULL)return 0;
	return (1+findLengthRecur(head->next));
}


// ITERATIVE METHOD
node* searchElement(node*head,int val)
{
	while(head!=NULL)
	{
		if(val==head->data)
			return head;
		head=head->next;
	}

	cout<<"value not found \n";
	return NULL;
}

// RECURSIVE METHOD

void searchElementRecur(node*head,int val,node*& ans)
{
	if(head==NULL)return;

	if(head->data==val)
		ans=head;

	searchElementRecur(head->next,val,ans);
}
void display(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);

	display(head);
	cout<<"enter the value to find\n";

	int val;
	cin>>val;
	node* k=searchElement(head,val);
	if(k)cout<<k->data<<"\n";

	display(head);
	cout<<"enter the value to find\n";

	cin>>val;

	node*ans;
	searchElementRecur(head,val,ans);
	cout<<ans->data;

}
