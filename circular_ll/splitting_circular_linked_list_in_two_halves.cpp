/*
Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Input:

You have to complete the method which takes 3 argument: The address of the head of the linked list , addresses of the head of the first and second halved resultant lists.. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:

Set the *head1_ref and *head2_ref to first resultant list and second resultant list respectively.


Constraints:

1<=T<=100
2<=N<=100


Example:

Input:
2
3
1 5 7
4
2 6 1 5

Output:
1 5
7
2 6
1 5
*/




/* The structure of linked list is the following
struct node
{
   int data;
   node* next;
};   */

//  function which splits the circular linked list.  head is pointer
// to head node of given lined list.  head1_ref and *head2_ref
// are pointers to head pointers of resultant two halves.

void splitList(struct node *head, struct node **head1_ref,   
                                          struct node **head2_ref)
{
    node*temp=head;
    int count=0;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);
    if(count&1)
    {
        int x=(count/2)+1;
        *head1_ref=head;
        node*temp=head;
        int cnt=1;
        while(cnt<x)
        {
            temp=temp->next;
            cnt++;
        }
        *head2_ref=temp->next;
        temp->next=*head1_ref;
        temp=*head2_ref;
        while(temp->next!=*head1_ref)
        {
            temp=temp->next;
        }
        temp->next=*head2_ref;
    }
    else
    {
        int x=(count/2);
        *head1_ref=head;
        node*temp=head;
        int cnt=1;
        while(cnt<x)
        {
            temp=temp->next;
            cnt++;
        }
        *head2_ref=temp->next;
        temp->next=*head1_ref;
        temp=*head2_ref;
        while(temp->next!=*head1_ref)
        {
            temp=temp->next;
        }
        temp->next=*head2_ref;
        
    }
}