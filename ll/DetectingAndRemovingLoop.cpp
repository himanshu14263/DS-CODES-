#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

//////////////////////////FUNCTION TO DISPLAY LL////////////////////////////////////////////
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
///////////////////////FUNCTION TO REMOVE LL///////////////////////////////////////////////
void removeloop(node*loop_node,node*a)
{
	node*p1=loop_node,*p2=loop_node;
	p1=p1->next;
	int k=1;
	while(p1!=p2)
	{
		p1=p1->next;
		k++;
	}
	p1=p2=loop_node;

	int h=0;
	while(h!=k)
	{
		p2=p2->next;
		h++;
	}

	while(p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}

	p1=p1->next;
	while(p1->next!=p2)
	{
		p1=p1->next;
	}

	p1->next=NULL;


}
//////////////////////////////FUNCTION TO REMOVE LOOP/////////////////////////////////////////////////
void DetectLoop(node*a)
{
	node*slow=a,*fast=a;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			cout<<"loop is found\n";
			return;
			//removeloop(slow,a);
		}
	}
	cout<<"No loop is present\n";
	return;
}
////////////////////////////FUNCTION TO DETECT AND REMOVE LOOP IN LL//////////////////////////////////
bool DetectAndRemoveLoop(node*a)
{
	node*slow=a,*fast=a;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			//cout<<"loop is found\n";
			removeloop(slow,a);
		}
	}
	return false;
}

//////////////////////////////////////CREATING NEW NODE AND INITIALISING IT//////////////////////////
node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main()
{
	////////////////////  COPIED CODE FOR CREATING LINKED LIST CONTAINING LOOP /////////////////////
    struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    /////////////////////////////CODE FOR DETECTING AND REMOVING LOOP//////////////////////////////

    DetectLoop(head);
    DetectAndRemoveLoop(head);
    cout<<"sending linked list for removal of loop ........... \n";
    cout<<"after the processing of nodes\n";
    DetectLoop(head);
    display(head);
    return 0;
}
