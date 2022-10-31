#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Queue
{
    int size = 100;
    int front = -1;
    int rear = -1;
    int *arr = new int;
};
int isfull(struct Queue *p)
{
    if (p->rear == p->size - 1)
        return 1;
    else
        return 0;
}
int isempty(struct Queue *p)
{
    if (p->front == p->rear)
        {return 1;}
    else
       { return 0;}
}
void enqueue(struct Queue *p, int data)
{
    if (isfull(p))
    {
        cout << "Queue is full"
             << "\n";
    }
    else
    {
        p->rear = p->rear+1;
        p->arr[p->rear] = data;
    }
}
int dequeue(struct Queue *p)
{
    if (isempty(p))
    {
        cout << "Queue is empty"
             << "\n";
    }
    else
    {
        p->front = p->front + 1;
        return p->arr[p->front];
    }
}
void show(struct Queue *p)
{
    for (int i = p->front + 1; i <= p->rear; i++)
    {
        cout << p->arr[i] << "\n";
    }
}
int main()
{
    struct Queue *q = new struct Queue;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
   
    show(q);
   dequeue(q);
   cout<<"after dequeue\n";
    show(q);
    return 0;
}