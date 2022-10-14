// Example implementation of Disjoint Set Union

//////////////////////////////////////////////////////////////////
/////                                                           //
////  Credits: Rahul Verma (CC @vrintle, CF @BlindingKnight)   ///
///  Institution: Delhi Technological University (aka. DCE)   ////
//                                                           /////
//////////////////////////////////////////////////////////////////

#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

class DSU {
public:
	vector<int> head;
	vector<int> size;
	DSU(int n) {
		head.assign(n + 1, 0);
		size.assign(n + 1, 1);
		for(int i = 1; i <= n; i++) {
			head[i] = i;
		}
	}
	int get(int x) {
		if(x != head[x]) {
			head[x] = get(head[x]);
		}
		return head[x];	
	}
	void U(int a, int b) {
		// we'll assume a as "head"
		a = get(a);
		b = get(b);
		if(a == b) return ;
		if(size[a] < size[b]) swap(a, b);
		head[b] = a;
		size[a] += size[b];
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	DSU set(n);
	while(m--) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if(s == "union") {
			set.U(a, b);
		} else {
			cout << (set.get(a) == set.get(b) ? "YES" : "NO") << '\n';
		}
	}
}

int32_t main() {
	auto start = high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cerr << duration.count() << " µs!" << '\n';
	return 0;
}
