#include <bits/stdc++.h>

using namespace std;


struct Node{
	int data;
	struct Node* next;
	Node(int x){
	data=x;
	next=NULL;
}
};

// the helper function is a recursive function.
// it works recursively until the right pointer reaches the end node.
// and at each point checks it with the corresponding node from the beginning -> left pointer
    
bool helper(Node* right, Node* &left){
    if(right==NULL) return true;
    bool ans = helper(right->next,left) && (right->data==left->data);
    left=left->next;
    return ans;
}
    
    
bool isPalindrome(Node *head)
{
    Node* left=head;
    return helper(head,left);
}



// function to print linked list
void printList(struct Node* head){
 Node* temp=head;
 while(temp!=NULL){
   cout<<temp->data<<" ";
   temp=temp->next;
 }
}



int main(){
 
    // take the linked ist as input
    Node* head=NULL; 
    Node* tail=NULL;

    int n;
    cin>>n;

    int inp;
    cin>>inp;
    head= new Node(inp);
    tail=head;
    for(int i=1;i<n;i++){
    cin>>inp;
    tail->next=new Node(inp);
    tail=tail->next;
    }

    // function to print the linked list.
    // printList(head);
    // cout<<"\n";

    if(isPalindrome(head)){
        cout<<"The given linked list is a Palindrome";
    }
    else{
        cout<<"The given linked list is not a Palindrome";
    }
  

  return 0;
}

