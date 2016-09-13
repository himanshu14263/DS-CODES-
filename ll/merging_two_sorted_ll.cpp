#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;
node* create_ll()
{
	node*head=NULL;
		node*temp;
		cout<<"enter the data for 3 nodes\n";
		for(int i=0;i<3;i++)
		{
			node*n=new node;
			n->next=NULL;

			cin>>n->data;

			if(head==NULL)
				temp=head=n;
			else
			{
				temp->next=n;
				temp=n;
			}
		}
		return head;
}
void display(node*head)
{
	node*temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data;
				temp=temp->next;
				cout<<" ";
			}
}
/////////////////// ITERATIVE METHOD USING DUMMY NODE TECHNIQUE /////////////////////////////////
node*merge(node*a,node*b)
{
	node dummy;
	node*tail=&dummy;
	while(1)
	{
		if(a==NULL)
		{
			tail->next=b;
			break;
		}
		else if(b==NULL)
		{
			tail->next=a;
			break;
		}
		if(a->data<=b->data)
		{
			tail->next=a;
			tail=a;
			a=a->next;
		}
		else
		{
			tail->next=b;
			tail=b;
			b=b->next;
		}
	}
	return dummy.next;
}

/////////////////////////   RECURSIVE METHOD-SIMPLE AND EASY TO IMPLEMENT ////////////////////
node* mergeRecur(node*a,node*b)
{
	node*result=NULL;
	if(a==NULL)return b;
	else if(b==NULL)return a;
	if(a->data<=b->data){result=a;result->next=merge(a->next,b);}
	else{ result=b;result->next=merge(a,b->next);}
	return result;
}
int main()
{

	cout<<"CREATING LL 1\n";
	node* a=create_ll();
	cout<<"CREATING LL 2\n";
	node*b=create_ll();

	display(a);
	cout<<"\n";
	display(b);
	cout<<"\n";

	///////////////// MERGING TWO LINKED LIST //////////////////

	int ch;
	node*d,*h;

	cout<<"1) ITERATIVE METHOD\n";
	cout<<"2) RECURSIVE METHOD\n";

	cout<<"enter ur choice\n";
	cin>>ch;

	switch(ch)
	{
		case 1:
			d=merge(a,b);
			display(d);
			break;
		case 2:
			h=mergeRecur(a,b);
			display(h);
			break;
	}






}
