#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string user_name;
    cin>>user_name;
    sort(user_name.begin(), user_name.end());
    
    for(int i=0; user_name[i]!='\0';) {
        if(user_name[i] == user_name[i+1])
            user_name.erase (user_name.begin() + i);
        else
            i++;
    }
    
    int size = user_name.size();
    if(size&1)
        cout<<"IGNORE HIM!";
    else
        cout<<"CHAT WITH HER!";

    return 0;
}