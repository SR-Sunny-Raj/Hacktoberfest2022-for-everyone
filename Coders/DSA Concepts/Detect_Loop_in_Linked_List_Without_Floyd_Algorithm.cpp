#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        int visited;
};

void push(Node **head_ref, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

bool detectLoop(Node *head)
{
    Node *ptr = head;
    while(ptr)
    {
        if(ptr->visited == 1) return true;
        ptr->visited = 1;
        ptr = ptr->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;

    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);

    // head->next->next->next->next->next = head;
    if(detectLoop(head)) cout << "Loop is present in the List\n";
    else cout << "No Loop is present\n";

    return 0;
}
