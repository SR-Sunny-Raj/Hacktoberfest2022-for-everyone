#include <bits/stdc++.h>
using namespace std;

// Next Greater Element
vector<int> NGE(vector<int> &v) {
    int n = v.size();
    vector<int> nge(n, n);
    stack<int> st;
    for(int i = 0; i < v.size(); ++i) {
        while(!st.empty() && v[i] > v[st.top()]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

// Previous Greater Element
vector<int> PGE(vector<int> &v) {
	int n = v.size();
    vector<int> pge(n, -1);
	stack<int> st;
	for(int i = v.size() - 1; i >= 0; --i) {
		while(!st.empty() && v[i] > v[st.top()]) {
			pge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	return pge;
}

// Next Smaller Element
vector<int> NSE(vector<int> &v) {
    int n = v.size();
    vector<int> nse(n, n);
    stack<int> st;
    for(int i = 0; i < v.size(); ++i) {
        while(!st.empty() && v[i] < v[st.top()]) {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nse;
}

// Privious Smaller Element
vector<int> PSE(vector<int> &v) {
	int n = v.size();
    vector<int> pse(n, -1);
	stack<int> st;
	for(int i = v.size() - 1; i >= 0; --i) {
		while(!st.empty() && v[i] < v[st.top()]) {
			pse[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	return pse;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> nge = NGE(v);
	vector<int> pge = PGE(v);
	vector<int> nse = NSE(v);
	vector<int> pse = PSE(v);
	for(int i = 0; i < n; ++i) {
		cout << v[i] << " " << nge[i] << " " << pge[i] << " " << nse[i] << " " << pse[i] << endl;
	}
}
