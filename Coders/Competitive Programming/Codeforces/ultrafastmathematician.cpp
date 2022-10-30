// problem link : https://codeforces.com/contest/61/problem/A

#include<iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '0';
        }
        else
        {
            s1[i] = '1';
        }
    }
    cout << s1 << endl;
    return 0;
}
