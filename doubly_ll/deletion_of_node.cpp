#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*prev;
};
typedef struct node node;
////////////////////////////////// CODE FOR DELETION OF NODE IN CIRCULAR LL /////////////////////////////
void deleteNode(node**head,int data){
	if(*head==NULL)
	{
		cout<<"the ll is empty \n";
		return;
	}
	node*temp=*head;
	while(temp->data!=data && temp!=NULL)
		temp=temp->next;
	if(temp==NULL){
		cout<<"value is not present for deletion\n";
		return;
	}
	else
	{
		if(temp==*head)
		{
			if(temp->next)
			{
				temp->next->prev=NULL;
				*head=temp->next;
				free(temp);
			}
			else
			{
				*head=NULL;
				free(temp);
			}
		}
		else if(temp->next==NULL)
		{
			temp->prev->next=NULL;
			free(temp);
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}
}
////////////////////////////////// CODE FOR CREATION OF CIRCULAR LINKED LIST ////////////////////////////
void insert_in_front(node**head,int data)
{
	node*n=new node;
	n->data=data;
	if(*head==NULL)
	{
		n->next=NULL;
		n->prev=NULL;
		*head=n;
	}
	else
	{
		n->next=(*head);
		(*head)->prev=n;
		n->prev=NULL;
		*head=n;
	}
}
void insert_after_x(node**head,int x,int val)
{
	node*n=new node;
	n->data=val;
	node*temp=*head;
	while(temp!=NULL && temp->data!=x)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"value not present \n";
		return;
	}
	else
	{
		if(temp->next==NULL)
		{
			temp->next=n;
			n->prev=n;
			n->next=NULL;
		}
		else
		{
			temp->next->prev=n;
			n->next=temp->next;
			temp->next=n;
			n->prev=temp;
		}
	}
}
void insert_in_end(node**head,int data)
{
	node*n=new node;
	n->data=data;
	node*temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=n;
	n->prev=temp;
	n->next=NULL;
}

void insert_before_x(node**head,int x,int data)
{
	node*n=new node;
	n->data=data;
	node*temp=*head;
	while((temp->data!=x) && (temp!=NULL))
		temp=temp->next;
	if(temp==NULL)
	{
		cout<<"value is not present in the ll\n";
		return ;
	}
	else if(temp==*head)
	{
		n->next=temp;
		temp->prev=n;
		n->prev=NULL;
		*head=n;
	}
	else
	{
		temp->prev->next=n;
		n->prev=temp->prev;
		n->next=temp;
		temp->prev=n;
	}
}
void display(node**head)
{
	node*temp=*head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	node*head=NULL;
	while(1)
	{
		cout<<"   MENU\n";
		cout<<"1) insert in the front \n";
		cout<<"2) insert in the end\n";
		cout<<"3) insert after x\n";
		cout<<"4) insert before x\n";
		int ch,x,data;
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"enter the data to insert\n";
			cin>>data;
			insert_in_front(&head,data);
			break;
		case 2:
			cout<<"enter the data to insert\n";
			cin>>data;
			insert_in_end(&head,data);
			break;
		case 3:
			cout<<"enter the data to insert \n";
			cin>>data;
			cout<<"enter the value after which you want to insert the data\n";
			cin>>x;
			insert_after_x(&head,x,data);
			break;
		case 4:
			cout<<"enter the data to insert\n";
			cin>>data;
			cout<<"enter the value before which you want to insert the data\n";
			cin>>x;
			insert_before_x(&head,x,data);
			break;
		}

		display(&head);
		cout<<"\n";
		cout<<"do you want to continue\n";
		int h;
		cin>>h;
		if(h==0)
			break;

	}

	while(1)
	{
		int x;
			cout<<"****************** NODE DELETION ****************************\n";
			cout<<"enter the node value to delete \n";
			cin>>x;
			deleteNode(&head,x);
			display(&head);
			cout<<"\n";

		int ch;
		cout<<"do you want to continue\n";
		cin>>ch;
		if(!ch)
			break;
	}



}
