#include <stdio.h>

int MAX = 10;

int a[10]; // Maximum size of Stack
int top=-1;

void push(int x)
{
    if (top >= (MAX - 1))
    {
        printf("Stack Overflow");
    }
    else
    {
        a[++top] = x;
        printf("%d  pushed into stack\n",x);
        
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int peek()
{
    if (top < 0)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

void print()
{
    for (int i = top; i > -1; i--)
    {
        printf("%d ", a[i]);
    }
}


int main()
{

        push(1);
        push(2);
        push(3);
        push(4);
        push(5);
        printf("%d Popped from stack\n",pop());
        printf("Top element is : %d\n", peek());
        printf("Elements present in stack :\n");
        print();
}
