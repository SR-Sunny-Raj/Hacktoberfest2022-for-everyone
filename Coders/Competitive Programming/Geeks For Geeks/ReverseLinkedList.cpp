class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head->next==NULL)return head;
        struct Node* prev =head;
        struct Node* curr = head->next;
        head->next = NULL;
        while(curr!=NULL)
        {
            struct Node* nextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
