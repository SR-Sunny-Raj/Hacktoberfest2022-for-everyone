//This is a C code of queue implemented using linked list
//It is menu-driven as has 4 functions : Insert into Queue(Enque),Delete from Queue(Deque), Display Queue(display), Exit from program(exit)

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

void enq(int data);
void deq();
void display();
void create();
 
void main()
{
    int no, ch, e;
    char c;
    create();
    do
    {
        printf("\nQUEUE MENU:\n(1)Enque\n(2)Deque\n(3)Display\n(4)Exit\n");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data element : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
        printf("\nWant to continue?\nEnter choice (y/n): ");
        scanf(" %c",&c);
    }while(c=='Y'||c=='y');
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    printf("\nQUEUE:\n");
    while (front1 != rear)
    {
        printf("%d <- ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\nError: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\nDequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\nDequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
}
 
