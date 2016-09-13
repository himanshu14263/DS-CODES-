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
		cout<<"enter the data for 8 nodes\n";
		for(int i=0;i<8;i++)
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

//////////////////////////////// REVERSING NODES IN GROUPS ////////////////////////////

node* rev_group(node*head,int k)
{
	node*curr=head,*next=NULL,*prev=NULL;
	int cnt=0;
	while(curr!=NULL && cnt<k)       //// here got error   NOTE:  here in place of curr we can't use next b/c then while loop will never run
	{
		next=curr->next;             ////  here got error
		curr->next=prev;
		prev=curr;
		curr=next;
		cnt++;
	}
	if(next!=NULL)
	{
		head->next=rev_group(next,k);
	}
	return prev;
}
int main()
{

	cout<<"CREATING LL 1\n";
	node* a=create_ll();

	display(a);
	cout<<"\n";

	////////////////////////  CALLING REVERSE IN GROUPS FUNCTION /////////////////////////////////
	int k;
	cout<<"enter the size of group for reversal\n";
	cin>>k;
	node*p=rev_group(a,k);
	display(p);

}
