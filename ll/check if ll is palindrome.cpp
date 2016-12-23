
// PROBLEM :: CHECK IF GIVEN LINKED LIST IS PALLINDROME OR NOT.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
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

void display(node*head)
{
	cout<<"	";
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

// METHOD 1 : USING STACK

bool isPalin1(node*head)
{
	if(head==NULL)
		return true;

	stack<char>s;
	node*temp=head;
	while(temp)
	{
		s.push(temp->data);
		temp=temp->next;
	}

	temp=head;
	while(temp)
	{
		char ch=s.top();
		s.pop();
		if(ch!=temp->data)
			return false;
		temp=temp->next;
	}

	return true;
}

// METHOD 2 : USING RECURSION (COOL)

bool isPalinUtil(node*&left,node*right)
{
	if(right==NULL)
		return true;

	bool isPalinsubStr = isPalinUtil(left,right->next);
	bool isEqual=((left->data)==(right->data))?1:0;

	left=left->next;
	int subAns=(isPalinsubStr && isEqual);

	return subAns;
}
bool isPalin(node*head)
{
	return (isPalinUtil(head,head));
}
int main()
{
	node*head=NULL;
	insertAtFront(head,'r');
	insertAtFront(head,'a');
	insertAtFront(head,'d');
	insertAtFront(head,'a');
	insertAtFront(head,'r');

	cout<<"   *** USING STACK ***\n";
	display(head);

	if(isPalin1(head))
		cout<<"	pallindrome\n";
	else
		cout<<"	not pallindrome\n";

	cout<<"\n\n\n";


	cout<<"   *** USING RECURSION ***\n";
		display(head);

		if(isPalin(head))
			cout<<"	pallindrome\n";
		else
			cout<<"	not pallindrome\n";

}

