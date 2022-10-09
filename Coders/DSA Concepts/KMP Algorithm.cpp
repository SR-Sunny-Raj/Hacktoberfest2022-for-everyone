// KMP (Knuth Morris Pratt) Algorithm

/* - Time Complexity: O(n)

The KMP algorithm is built to tackle the limitations of the naïve method of pattern matching which 
involves repeated iteration and backtracking of the string and the pattern to be matched.

- The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than 
once in the pattern) of the pattern and improves the worst-case complexity to O (m + n) = O(n); 
m denotes the length of the pattern and n denotes the length of the string.

- The basic idea behind KMP’s algorithm is whenever we detect a mismatch (after some matches), 
we already know some of the characters in the text of the next window.

- Precomputation: We precompute and prepare a $pi$ table of the pattern to be matches in the 
pi table pi[i] will denotes the longest proper prefix starting in the interval [0 → i] which is also a 
suffix in the interval [0 → i].

*/

//Preparation of Precomputed Vector


#include <bits/stdc++.h>

using namespace std;

vector <int> prefixtable(string t)
{
	int n = t.length();	
	vector <int> pit(n + 1);

	
	int len = 0;
	int i = 1;
	pit[0] = 0;// always 0 in the case of first index
	
// prepares pitable for i = 1 -> i = n - 1
	while(i < n)
{
	if(pit[i] == pit[len])
	{
		len++;
		pit[i] = len;
		i++;
	}
	else{
	if(len != 0)
		len = pit[len - 1];
	else{
		pit[i] = 0;
		i++;
	}
	}
}	

return pit;
}

//or

vector <int> prefixtable(string s)
{
	int n = s.length();
	vector <int> pit(n);
	
	for(int i = 0; i < n; i++)
	{
		int j = pit[i - 1];
		while(j > 0 && s[i] != s[j])
				j = pit[j - 1];

		if(s[i] == s[j])
			j++;

		pit[i] = j;
    }
return pit;
}


/*

Evaluation: The evaluation takes place by comparing the ith and jth positions of the string and the pattern. 
If they match, we will increment `i` and `j` . If they don't match, we will change  j = pit[j - 1]
 as long as j != 0 . If j == 0 then we know that there is no repetitive pattern up to i  therefore we will 
 change  i = i + 1 and continue iterating through the string.

*/

void evaluator(string s, string t, vector <int> pit)
{
	int n = s.length();
	int m = t.length();
	int i = 0, j = 0;
	while(i < n)
	{
		if(s[i] == t[j])
		{i++; j++;}
		
		if(j == m){
			cout << "starting index" << i - j;
			j = pit[j - 1];//continue to search for other occurances of the pattern which may
			//contain characters from the current found substring;
			}
		else if(i < n && s[i] != t[j])
	{
		if(j != 0)
			j = pit[j - 1];//Start checking from the last position of a recurrent pattern in t
		else
			i++;
	}	
}
}
