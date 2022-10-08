#include <iostream>
#include <string>
#include<stack>
using namespace std;
bool isBalanced(string expression)
{
    // Write your code here
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (s.empty() && expression[i] == ')')
            return false;
        else if (s.empty())
            s.push(expression[i]);
        else if (expression[i] == '(')
            s.push(expression[i]);
        else if (expression[i] == ')' && s.top() == '(')
            s.pop();
        else
            s.push(expression[i]);
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}