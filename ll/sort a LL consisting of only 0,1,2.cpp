// PROBLEM :: SORT A LL CONSISTING OF ONLY 0,1,2

// REFER NOTES FOR DETAILED EXPLANATION.
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

void sort012(node*head)
{
	if(head==NULL)return;

	int arr[3]={0};

	node*temp=head;

	while(temp)
	{
		arr[temp->data]++;
		temp=temp->next;
	}


	temp=head;

	int i=0;
	while(temp)
	{
		if(arr[i]==0)
			i++;
		while(arr[i])
		{
			temp->data=i;
			arr[i]--;
			temp=temp->next;
		}
	}
}

int main()
{
	node*head=newnode(0);
	head->next=newnode(1);
	head->next->next=newnode(0);
	head->next->next->next=newnode(2);
	head->next->next->next->next=newnode(1);
	head->next->next->next->next->next=newnode(2);
	head->next->next->next->next->next->next=newnode(1);

	cout<<"the original list is ::\n";
	display(head);

	sort012(head);

	cout<<"the sorted list is ::\n";
	display(head);


}

