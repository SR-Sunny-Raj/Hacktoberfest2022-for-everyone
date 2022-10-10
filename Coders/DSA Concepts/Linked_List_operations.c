//This is a C program to implement operations like creation, deletion and searching on linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;  //global pointer

void create(int a[],int n){
    int i;
    struct node *temp;
    struct node *last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void display(struct node *p){
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
}

void rdisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        rdisplay(p->next);
    }
}

int count(struct node *p){
    int count=0;
    while(p!=NULL){
        count=count+1;
        p=p->next;
    }
    return count;
}
int Rcount(struct node *p){
    if(p==NULL)
        return 0;
    else{
        return Rcount(p->next)+1;
    }
}

int sum(struct node *p){
    int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct node *p){
    if(p==0)
        return 0;
    else{
        return Rsum(p->next)+p->data;
    }
}

int max(struct node *p){
    int max=-32768;
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int Rmax(struct node *p){
    int x=0;
    if(p==0)
        return INT_MIN;
    x=Rmax(p->next);
    if(x>p->data){
        return x;
    }
    else return p->data;
}

int min(struct node *p){
    int min=INT_MAX;
    while(p!=0){
        if(p->data<min){
            min=p->data;
        }
        p=p->next;
    }
    return min;
}

struct node * lsearch(struct node *p, int key){
    struct node *q;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct node * rsearch(struct node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return rsearch(p->next,key);
}

int main(){
    int a[]={3,4,5,6,7,8,7,9};
    struct node *temp,*temp2;
    create(a,8);
    temp=lsearch(first,9);
    temp2=rsearch(first,9);
    display(first);
    printf("\n");
    rdisplay(first);
    printf("\nlength is %d",count(first));
    printf("\nlength using recusrsion is %d",Rcount(first));
    printf("\nsum is %d",sum(first));
    printf("\nsum using recursion is %d",Rsum(first));
    printf("\nmax is %d",max(first));
    printf("\nmin is %d",min(first));
    printf("\nmax using recursion is %d",Rmax(first));
    printf("\nkey is found %d",temp->data);
    printf("\nkey using recursion is found %d",temp2->data);
    return 0;
}
