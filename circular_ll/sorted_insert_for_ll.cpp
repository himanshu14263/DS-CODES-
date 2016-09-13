/*
Given a sorted circular linked list, insert a newnode so that it remains a sorted circular linked list.

Input:

In this problem, method takes two argument: the address of the head of the linked list and the data which you have to insert. The function should not read any input from stdin/console.
The Node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set the * head_ref to head of resultant linked list.

Note: If you use "Test" or "Expected Output Button" use below example format

Constraints:

1<=T<=100
0<=N<=200

Example:

Input:
2
3                           Size of Linked List
1 2 4                    Elements of Linked List
2                           Element to be inserted
4
1 4 7 9
5

Output:

1 2 2 4
1 4 5 7 9
*/


/* structure for a node */
/*
struct node
{
  int data;
  struct node *next;
};
 */


////////////////////////    STEPS TO SOLVE THE PROBLEM  ///////////////////////////////
/*
1) Linked List is empty:  
    a)  since new_node is the only node in CLL, make a self loop.      
          new_node->next = new_node;  
    b) change the head pointer to point to new node.
          *head_ref = new_node;
2) New node is to be inserted just before the head node:    
  (a) Find out the last node using a loop.
         while(current->next != *head_ref)
            current = current->next;
  (b) Change the next of last node. 
         current->next = new_node;
  (c) Change next of new node to point to head.
         new_node->next = *head_ref;
  (d) change the head pointer to point to new node.
         *head_ref = new_node;
3) New node is to be  inserted somewhere after the head: 
   (a) Locate the node after which new node is to be inserted.
         while ( current->next!= *head_ref && 
             current->next->data < new_node->data)
         {   current = current->next;   }
   (b) Make next of new_node as next of the located pointer
         new_node->next = current->next;
   (c) Change the next of the located pointer
         current->next = new_node; 
*/
void sortedInsert(struct node** head_ref, int x)
{
    node*n=new node;
    n->data=x;
    if(*head_ref==NULL)
    {
        n->next=n;
        *head_ref=n;
    }
    else if((*head_ref)->data>x)
    {
        node*temp=*head_ref;
        while((temp->next)!=*head_ref) //////   THIS I FORGOT DURING THE CODING 
            temp=temp->next;
        n->next=*head_ref;
        *head_ref=n;
        temp->next=*head_ref;
    }
    else
    {
        node*temp=*head_ref;
        while(((temp->next)->data)<x && (temp->next)!=(*head_ref))
            temp=temp->next;
        if((temp->next)==(*head_ref))
        {
            n->next=*head_ref;
            temp->next=n;
        }
        else
        {
            n->next=temp->next;
            temp->next=n;
        }
        
    }
}