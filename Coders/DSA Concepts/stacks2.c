#include<stdio.h>
#include<stdlib.h>
 
int* stack_arr[8];
int top=-1;

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow");
        return;
    }
    stack_arr[++top]=data;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow");
        return 1;
    }
    int temp;
    temp=stack_arr[top--];
    return temp;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else   
        return 0;
}

int isFull()
{
    if(top==7)
        return 1;
    else
        return 0;
}

void print()
{
    printf("\nThe elements of the stack are : ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    } 
}

int peek()
{
    return stack_arr[top];
}

int main()
{
    int data, choice;

    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Print all elements in Stack\n4. Peek\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter element you want to push : ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data=pop();
                printf("%d is deleted from the stack.\n", data);
                break;
            case 3:
                print();
                break;
            case 4:
                data=peek();
                printf("%d", data);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Wrong choice.\n");
                break;
        }
    }
    return 0;
}