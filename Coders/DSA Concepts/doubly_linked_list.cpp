
#include <iostream>
using namespace std;

typedef struct Node {
   int data;
   struct Node *pre;
   struct Node *next;
}Node;
Node* head = NULL;

void print() {
   Node* ptr;
   ptr = head;
   while(!(ptr == NULL)) {
      cout<< ptr->data <<"\t";
      ptr = ptr->next;
   }
}



void insert(int info) {
    Node* newnode = (struct Node*) malloc(sizeof(Node));
    newnode->next = head;
    newnode->pre = NULL;
    newnode->data = info;
    if(!(head == NULL))
        head->pre = newnode ;
    head = newnode;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    cout<<"doubly linked list::: "<<endl;
    print();
    return 0;
}