#include <bits/stdc++.h>
using namespace std;

void first_last_occ(int arr[], int n, int find)
{
	int first = -1, last = -1;
	for (int i = 0; i < n; i++) 
    {
		if (find != arr[i])
			continue;
		if (first == -1)
			first = i;
		last = i;
	}
	if (first != -1)
		cout << "First = " << first<< " & Last = " << last;
	else
		cout << "Not Found in the Array";
}
int main()
{
	int arr[] = { 1,2,2,4,6,7,7,7,8,8,9};
	int n = sizeof(arr) / sizeof(int);
	int find = 7;
	first_last_occ(arr, n, find);
	return 0;
}


