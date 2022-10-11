

#include <iostream>

using namespace std;

int main()
{
   char a[]={'a','b','c'}; // array of character

   // for given n we have n*(n+1)/2 substring (this also include one empty substring)

   // for this example total non empty substring is (3*4)/2 = 6-1 = 5
   // Time complexity= O(N*N*N)
   
   int n=3; // array size of n==3
   for(int length =1; length<=n; length++){   // length of substring may vary from 1 to n
       for(int start=0; start<=n-length; start++){
               int end=start+length-1;
           for(int temp=start; temp<=end; temp++){
                cout<<a[temp];
           }
           cout<<"\n";
       }
   }

    return 0;
}
