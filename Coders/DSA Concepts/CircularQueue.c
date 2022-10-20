// Circular Queue Implementation in C 
#include <stdio.h>
#define Max_Size 5

int queue[Max_Size];
int front=-1,rear=-1;

// Function to check if queue is full
int isFull(){
    if((front==rear+1)||(front==0&&rear==Max_Size))
        return 1;
    else
        return 0;
}

// Function to check if queue is empty
int isEmpty(){
    if(front==-1)
        return 1;
    else
        return 0;
}

// Function to enqueue a element in a queue
void Enqueue(int item){
    if(isFull())
        printf("\nQueue is Full...\n");
    else{
        if(front==-1)
            front=0;
        rear=(rear+1)%Max_Size;
        queue[rear]=item;
        printf("\n%d has been enqueued..\n",item);
    }
}

// Function to Dequeue a element from a queue
int Dequeue(){
    int item;
    if(isEmpty()){
        printf("\n Queue is Empty..\n");
        return -1;
    }
    else{
        item=queue[front];

        // If queue has only one elment
        if(front==rear){
            front=-1;
            rear=-1;
        }

        else
            front=(front+1)%Max_Size;
        printf("\n%d has been Dequeued from the queue...\n",item);
        return item;
    }
}

// Function to Display the Queue
void display(){
    int i;
    if(isEmpty())
        printf("\nQueue is Empty...\n");
    else{
        printf("\nThe Queue is:\n");
        for(i=front;i!=rear;i=(i+1)%Max_Size){
            printf("%d\t",queue[i]);
        }
        printf("%d ",queue[i]);
    }
}

int main(){
    Dequeue();//Queue is Empty, so it fails
    
    //5 elements are enqueued
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);

    Enqueue(6);//This is not possible because Queue is full

    display();

    Dequeue();
    display();
    
    Enqueue(7);
    display();

    Enqueue(8);//This is not possible because Queue is full

    return 0;
}