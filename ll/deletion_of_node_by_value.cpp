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
			while((temp)!=NULL)
			{
				cout<<(temp)->data;
				(temp)=(temp)->next;
				cout<<" ";
			}
}

////////////////// FUCTION TO DELETE ANY NODE WITH GIVEN KEY VALUE //////////////////////
void del_value(node**head,int val)
{
	node**curr=head;
	node*prev=NULL;
	if(*head==NULL)
	{
		cout<<"ll is empty \n";
		return;
	}
	while((*curr)!=NULL && (*curr)->data!=val)
	{
		prev=*curr;
		*curr=(*curr)->next;
	}
	if(prev==NULL)
	{
		*head=(*head)->next;
		free(curr);
	}
	else if(*curr==NULL)
		cout<<"value is not present in the linked list\n";
	else
	{
		prev->next=(*curr)->next;
		free(curr);
	}
}
int main()
{
	node* head=create_ll();
	display(head);

	int val;
	int ch;

	////////////////// TO DELETE ANY NODE WITH GIVEN KEY VALUE ///////////////////////
	while(ch)
	{
		cout<<"enter the value to delete \n";
		cin>>val;
		del_value(&head,val);
		display(head);
		display(head);
		cout<<"do u want to continue\n";
		cin>>ch;
	}

}
