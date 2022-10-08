#include <iostream>
#include <string>
#include<stack>
using namespace std;
bool checkRedundantBrackets(string input)
{
    // Write your code here
    stack<char> s;
    int i = 0, j = 0;
    int count = 0;
    while (input[i] != '\0')
    {
        while (input[i] != ')')
        {
            if (input[i] == '\0')
            {
                return false;
            }
            s.push(input[i]);
            i++;
        }
        if (input[i] == ')')
        {
            if (s.empty())
                return false;
            while (s.top() != '(')
            {
                s.pop();
                count++;
            }
            if (count == 0 || count == 1)
            {
                return true;
            }
            else
            {
                s.pop();
                count = 0;
            }
        }
        i++;
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}