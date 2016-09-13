#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
typedef struct node node;
int switchNodes(int a,int b,node** head)
{
	node*xprev,*x,*y,*yprev;
	xprev=yprev=NULL;
	x=y=*head;

	while(x!=NULL && x->data!=a)
	{
		xprev=x;
		x=x->next;
	}

	while(y!=NULL && y->data!=b)
	{
		yprev=y;
		y=y->next;
	}

	if(x==y)		         // values are same so swap is not possible
		return 0;

	if(x==NULL || y==NULL)   //  either one of them is not present in the linked list.
		return 0;

	//////////////////  main logic  ////////////////
	if(xprev==NULL)
		*head=y;
	else
		xprev->next=y;

	if(yprev==NULL)
		*head=x;
	else
		yprev->next=x;

	node*temp;
	temp=x->next;
	x->next=y->next;
	y->next=temp;



	return 1;
}
int main()
{
	////////////////CREATING LINKED LIST ////////////////////////////////////
	node*head=NULL;
	for(int i=0;i<6;i++)
	{
		node*n=new node;
		n->next=NULL;
		cout<<"enter the data for the node\n";
		cin>>n->data;
		node*temp;
		if(head==NULL)
			temp=head=n;
		else
		{
			temp->next=n;
			temp=n;
		}
	}

	////////////////////// DISPLAYING LINKED LIST ////////////////////////////
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";

	///////////////// SWITCHING NODES ////////////////////////////

	int t=1;
	while(t)
	{

		int a,b;
		cout<<"enter the data of nodes u want to switch\n";
		cin>>a>>b;
		int h=switchNodes(a,b,&head);

		if(h==0)
			cout<<"switching of nodes is not possible\n";
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}

		cout<<"do you want to continue\n";
		cin>>t;

	}

}

//////////////////  IMPORTANT NOTES //////////////////

/*
 * 1) how to pass a reference of pointer to a function and use it.
 * 2) always draw diagram and then write code for making connections b/w the nodes.
 *
 */
