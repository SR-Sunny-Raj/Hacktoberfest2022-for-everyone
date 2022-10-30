#include <iostream>
using namespace std;

class Stack {
    
    public:
       int top;
       int *arr;
       int size;
       
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    
    void push(int element){
        
        if(size - top >1){
            top++;
            arr[top] = element; 
        }
        else {
            cout<<"Stack is full/overflow"<<endl;
        }
    }
    
    void pop(){
         if(top>=0){
            cout<<"Removed the top element "<<arr[top]<<endl;
            top --;  
            
         }
         else {
            cout<<"Stack is isEmpty/Underflow"; 
         }
    }
    
    int peek() {
          if(top>=0){
              cout<<arr[top]<<endl;
              return arr[top];
          }
          else {
              cout<<"Stack empty"<<endl;
              return -1;
          }
         
    }
    
    void isEmpty(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
        }
        else {
            cout<<"Stack is not empty"<<endl;
        }
    }
};

int main()
{
    Stack s1(2);
    s1.push(10);
    s1.push(14);
    s1.peek();
    s1.isEmpty();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.isEmpty();
    return 0;
}