#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
// BFS Implementation

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> vis(V, 0);
	vis[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		bfs.push_back(node);
		for (auto it : adj[node])
		{
			if (!vis[it])
			{
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}

int main() {
	int n, m; cin >> n >> m;			// Input number of vertices and edges
	for(int i = 0; i < m; ++i) {
		int v1, v2; cin >> v1 >> v2;	// Input edges connecting two vertices
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	vector<int> v = bfs(n, g);
	for(int i=0; i<n; i++)
		cout << v[i] << " ";
}
