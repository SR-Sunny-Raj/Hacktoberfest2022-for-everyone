  // problem name : Find Peak element
 // Problem Link : https://leetcode.com/problems/find-peak-element/#:~:text=Find%20Peak%20Element%20%2D%20LeetCode&text=A%20peak%20element%20is%20an,to%20any%20of%20the%20peaks.

 #include<iostream>

using namespace std;

int peakEleBruteForce(int arr[], int n) {
  if (arr[0] >= arr[1])
    return arr[0];

  for (int i = 1; i < n - 1; i++)
    if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
      return arr[i];

  return arr[n - 1];
}

int main() {

  int arr[] = {3, 5, 4, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Peak Element is " << peakEleBruteForce(arr, n);

  return 0;
}



