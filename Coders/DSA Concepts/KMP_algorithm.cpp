#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, vector<int> &lps)
{
	int m = pat.size();
	int len = 0;

	int i = 1;
	while (i < m) 
	{
		if (pat[i] == pat[len]) 
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) 
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(string pat, string txt)
{
	int m = pat.size();
	int n = txt.size();

	vector<int> lps(m);
	lps[0] = 0;
	
	computeLPSArray(pat, lps);

	int i = 0, j = 0; 
	while ((n - i) >= (m - j)) 
	{
		if (pat[j] == txt[i]) 
		{
			j++;
			i++;
		}

		if (j == m) 
		{
			cout << "Found pattern at index: " << i - j;
			j = lps[j - 1];
		}

		else if (i < n && pat[j] != txt[i]) 
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}
