/**
*     All limitations are self-imposed. – Oliver Wendell Holmes
**/

// Problem link- https://codeforces.com/contest/1263/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
void solve()
{
  int arr[3];
  cin>>arr[0]>>arr[1]>>arr[2];
  sort(arr,arr+3);
  reverse(arr,arr+3);
  if(arr[0]>=arr[1]+arr[2])
  {
    cout<<arr[1]+arr[2]<<endl;
  }
  else
  {

    cout<<(arr[0]+arr[1]+arr[2])/2<<endl;
  }
 



}
int32_t main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t=1;
  cin>>t;
  while(t--)
  {
    solve();
  }


  return 0;
}
