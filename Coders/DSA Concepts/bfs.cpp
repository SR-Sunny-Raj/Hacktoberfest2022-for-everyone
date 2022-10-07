#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];	// To store the edges of the graph
bool vis[N];		// To check if any node is visited or not
int level[N];		// To store the level of each node

// BFS Implementation

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while(!q.empty()) {
		int vertex = q.front();
		q.pop();
		for(auto &child: g[vertex]) {
			if(vis[child]) continue;
			q.push(child);
			cout << child << endl;
			vis[child] = true;
			level[child] = level[vertex] + 1;
		}
	}
}

int main() {
	int n, m; cin >> n >> m;			// Input number of vertices and edges
	for(int i = 0; i < m; ++i) {
		int v1, v2; cin >> v1 >> v2;	// Input edges connecting two vertices
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	bfs(1);
}
