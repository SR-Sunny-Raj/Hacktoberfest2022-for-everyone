//problem link : https://codeforces.com/contest/1335/problem/A

#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int t;
    cin >> t;
    double n;
    long long int ans;
    while (t--)
    {
        ans = 0;
        cin >> n;
        ans = ceil((n / 2) - 1);
 
        cout << ans << endl;
    }
 
    return 0;
}
