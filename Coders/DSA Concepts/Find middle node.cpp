#include <bits/stdc++.h>
using namespace std;
  
/* Link list node */
typedef struct Node {
    int data;
    struct Node* next;
} SLL;
  
/* Function to get the middle node in the linked list*/
void findMiddle(SLL *head)
{
    /*  fast pointer moves two times fast as compared to slow pointer
        slow pointer iterates through each node but fast pointer skips every other node
        when the fast pointer reaches to the end then the slow pointer will be at the middle node
    */
    SLL *slow = head;
    SLL *fast = head;

    // iterating slow and fast pointers until fast becomes null or fast->next becomes null
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle node data : %d\n", slow->data);
}
  
void push(SLL** head_ref, int new_data)
{
    /* allocate node */
    SLL* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
  
// Driver Code
int main()
{
    /* Start with the empty list */
    SLL* head = NULL;
  
    // create linked 20->4->15->35->10->44->91->2->31
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    push(&head, 10);    // Middle Node
    push(&head, 44);
    push(&head, 91);
    push(&head, 2);
    push(&head, 31);
  
    findMiddle(head);

    return 0;
}
