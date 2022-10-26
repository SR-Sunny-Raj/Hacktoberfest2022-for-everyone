// C++ program to convert an integer to roman numeral

#include <iostream>
  
using namespace std; 

string roman(int n) {

    string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int r_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string res = "";

    for (int i = 0; i < 13; i++)
    {
        while(n - r_values[i] >= 0)
        {
                res += r[i];
                n -= r_values[i];
        }
    }

    return res;
}

  
int main()  
{  
    int n;
    cout << "Enter the Integer : ";
    cin >> n;
	cout <<" Roman : " << roman(n) << endl;
				
    return 0;  
} 
