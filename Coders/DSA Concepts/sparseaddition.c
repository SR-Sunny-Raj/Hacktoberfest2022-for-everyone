#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row, col;
    int val;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
        ptr=ptr->next;
    }
}

struct node * create(struct node *head,int r,int c,int v)
{
   struct node * new_node = (struct node *)malloc(sizeof(struct node));
   struct node *ptr;
   new_node->row=r;
   new_node->col=c;
   new_node->val=v;
   new_node->next=NULL;
   if(head==NULL)
   {
    head=new_node;
    ptr=head;
   }
   else
   {
        ptr->next=new_node;
        ptr=ptr->next;  
   }
   //display(head);
   return head;
}

struct node * add(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *ptr1=head1,*ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if((ptr1->row==ptr2->row) && (ptr1->col==ptr2->col))
        {
            head3=create(head3,ptr1->row,ptr1->col,(ptr1->val+ptr2->val));
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if((ptr1->row==ptr2->row) && (ptr1->col!=ptr2->col))
        {
            if(ptr1->col<ptr2->col)
            {
                head3=create(head3,ptr1->row,ptr1->col,ptr1->val);
                ptr1=ptr1->next;
            }
            else
            {
                head3=create(head3,ptr1->row,ptr2->col,ptr1->val);
                ptr2=ptr2->next;
            }
        }
        else if(ptr1->row<ptr2->row)
        {
            head3=create(head3,ptr1->row,ptr1->col,ptr1->val);
            ptr1=ptr1->next;
        }
        else
        {
            head3=create(head3,ptr2->row,ptr2->col,ptr2->val);
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL)
    {
        while(ptr1!=NULL)
        {
            head3=create(head3,ptr1->row,ptr1->col,ptr1->val);
            ptr1=ptr1->next;
        }
    }
    if(ptr2!=NULL)
    {
        while(ptr2!=NULL)
        {
            head3=create(head3,ptr2->row,ptr2->col,ptr2->val);
            ptr2=ptr2->next;
        }
    }
    return head3;
}

int main()
{
    struct node *head1=NULL,*head2=NULL,*head3=NULL;

    int r1,c1;
    printf("Enter the no of rows and columns : ");
    scanf("%d %d",&r1,&c1);
    int ar1[r1][c1];
    printf("Enter the elements of matrix 1 : ");
    for(int i =0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        scanf("%d",&ar1[i][j]);
    }
    printf("The Matrix 1 :\n");
    for(int i =0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        printf("%d ",ar1[i][j]);
        printf("\n");
    }
    printf("Spare matrix 1 : \n");
    for(int i =0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            if(ar1[i][j]!=0)
            {
            head1=create(head1,i,j,ar1[i][j]);
            //display(head1);
            }
        }
    }
    display(head1);

    int r2,c2;
    printf("Enter the no of rows and columns : ");
    scanf("%d %d",&r2,&c2);
    int ar2[r2][c2];
    printf("Enter the elements of matrix 2 : ");
    for(int i =0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        scanf("%d",&ar2[i][j]);
    }
    printf("The Matrix 2 :\n");
    for(int i =0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        printf("%d ",ar2[i][j]);
        printf("\n");
    }
    printf("Spare matrix 2 : \n");
    for(int i =0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            if(ar2[i][j]!=0)
            {
            head2=create(head2,i,j,ar2[i][j]);
            //display(head2);
            }
        }
    }
    display(head2);

    if(r1==r2 && c1==c2)
    {
        printf("Sparse matrix addition : \n");
        head3=add(head1,head2,head3);
        display(head3);
    }
    else
    printf("Sparse matrix addition not possible");

    return 0;
}
