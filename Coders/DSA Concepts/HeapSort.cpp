#include<iostream>
using namespace std;

void disp(int *arr, int size) {
   for(int i = 1; i<=size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void heapify(int *arr, int n) {
   int i, par, l, r, node;
   // create max heap

   for(i = 1; i<= n; i++) {
      node = i; par = (int)node/2;
      while(par >= 1) {
         //if new node bigger than parent, then swap
         if(arr[par] < arr[node])
            swap(arr[par], arr[node]);
         node = par;
         par = (int)node/2;//update parent to check
      }
   }
}

void heapSort(int *arr, int n) {
   int i;

   for(i = n; i>= 1; i--) {
      heapify(arr, i);//heapify each time
      swap(arr[1], arr[i]);//swap last element with first
   }
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n+1]; //effective index starts from i = 1.
   cout << "Enter numbers:" << endl;

   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }

   cout << "Array before Sorting: ";
   disp(arr, n);
   heapSort(arr, n);
   cout << "Array after Sorting: ";
   disp(arr, n);
}
