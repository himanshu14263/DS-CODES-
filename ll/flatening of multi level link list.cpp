
// PROBLEM :: FLATTENING OF MULTILEVEL LINK LIST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*child;
};

///////////////////////////  COPIED CODE FOR CREATION OF MULTILEVEL LINK LIST  /////////////////////////

// Macro to find number of elements in array
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// A utility function to create a linked list with n nodes. The data
// of nodes is taken from arr[].  All child pointers are set as NULL
struct node *createList(int *arr, int n)
{
    struct node *head = NULL;
    struct node *p;

    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct node *)malloc(sizeof(*p));
        else {
            p->next = (struct node *)malloc(sizeof(*p));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}

// This function creates the input list.  The created list is same
// as shown in the above figure
struct node *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};

    /* create 8 linked lists */
    struct node *head1 = createList(arr1, SIZE(arr1));
    struct node *head2 = createList(arr2, SIZE(arr2));
    struct node *head3 = createList(arr3, SIZE(arr3));
    struct node *head4 = createList(arr4, SIZE(arr4));
    struct node *head5 = createList(arr5, SIZE(arr5));
    struct node *head6 = createList(arr6, SIZE(arr6));
    struct node *head7 = createList(arr7, SIZE(arr7));
    struct node *head8 = createList(arr8, SIZE(arr8));


    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;


    /* Return head pointer of first linked list.  Note that all nodes are
       reachable from head1 */
    return head1;
}
//////////////////////////////////  COPIED TILL HERE  /////////////////////////////////////////////


void display2(node*head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}


void flatten(node*head)
{
	if(!head)return;

	node*curr=head;
	node*last=head;

	// make last always point to the end of the list
	while(last->next)
		last=last->next;

	// keep iterating till "curr" is not null
	while(curr)
	{
		if(curr->child)						// if you find a child then take that child to the last of link list.
			last->next=curr->child;

		while(last->next)					// now again make last point to the end of the list.
			last=last->next;
		curr=curr->next;
	}
}
int main()
{
	node*head=createList();

	display(head);
	cout<<"\n";

	flatten(head);

	display(head);

}

