
// PROBLEM :: ADD 1 TO A NUMBER REPRESENTED AS LL

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}


// used recursion to reach the end of the list and then add 1 to the last node.
// if carry is generated then add it in next nodes data and check for carry
// keep doing this till you reach the begining of the list
// when reached the fornt check if there is still carry remaining
// if you have carry then create node with it and add it to head or front.

void Add1Recur(node*head,int&carry,int num)
{
	if(head==NULL)return;
	if(head->next==NULL)
	{
		int sum=head->data+num;
		if(sum>9)
		{
			sum%=10;
			carry=1;
		}
		head->data=sum;
		return;
	}

	Add1Recur(head->next,carry,num);

	int sum=(head->data+carry);
	carry=0;
	if(sum>9)
	{
		sum%=10;
		carry=1;
	}
	head->data=sum;

}

void Add1(node*&head,int num)
{
	int carry=0;
	Add1Recur(head,carry,num);

	if(carry>0)
	{
		node*n=new node;
		n->data=carry;
		n->next=head;
		head=n;
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(9);
	head->next->next=newnode(1);
	head->next->next->next=newnode(9);


	cout<<"TEST CASE 1 \n";
	display(head);
	int num=1;
	Add1(head,num);
	cout<<"\n";
	display(head);


	node*head2=newnode(9);
	head2->next=newnode(9);
	head2->next->next=newnode(9);
	head2->next->next->next=newnode(9);


	cout<<"\n\nTEST CASE 2\n";

	display(head2);
	num=1;
	Add1(head2,num);
	cout<<"\n";
	display(head2);
}

