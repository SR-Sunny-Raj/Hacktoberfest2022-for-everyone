#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
     Node(int val){
        this->val=val;
        this->next=nullptr;
    }
};

class customLinkedList{
    public:
    Node *head,*tail;
    int size=0;
    customLinkedList(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }

void addLast(int val){
    Node *node= new Node(val);
        if(size==0)
        {
        size++;
        head=node;
        tail=node;
         return;
        }
    tail->next=node;
    tail=node;
    size++;
}
void addFirst(int val){
    Node *node= new Node(val);
    if(size==0)
    {
        addLast(val);
        return;
    }
    node->next=head;
    head=node;
    size++;
}
void removeFirst(){
    if(size==0){
        cout<<"LinkedList is empty"<<endl;
        return;
    }
    if(size==1){
        size--;
        head=nullptr;
        tail=nullptr;
        return;
    }
    size--;
    head=head->next;
}
void removeLast(){
    if(size==0){
        removeFirst();
        return;
    }
    size--;
    Node *p=head;
    while(p->next!=tail){
        p=p->next;
    }
    p->next=nullptr;
    tail=p;
}
void display(){
    Node *p=head;
    while(p!=nullptr){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
};

int main(){
    customLinkedList *c1=new customLinkedList();
    c1->addLast(10);
    c1->addLast(20);
    c1->addLast(30);
    c1->addFirst(40);
    c1->addFirst(40);
    c1->display();
    c1->removeFirst();
    c1->removeFirst();
    c1->display();
    c1->removeLast();
    c1->display();
    return 0;
}
