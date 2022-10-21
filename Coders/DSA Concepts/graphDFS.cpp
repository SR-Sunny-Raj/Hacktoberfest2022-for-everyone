#include <bits/stdc++.h>
using namespace std;

void dfsOfGraph(int node, vector<int> &visited, vector<int> adj[], vector<int> &dfstraversal){
    dfstraversal.push_back(node);
    visited[node] = 1;
    for(auto it: adj[node]){

        if(!visited[it]){
            dfsOfGraph(it, visited, adj, dfstraversal);
        }
    }
}

vector<int> dfs(int n, vector<int> adj[]){
    vector<int> dfstraversal;
    vector<int> visited(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]){
            dfsOfGraph(i, visited, adj, dfstraversal);
        }
    }

    return dfstraversal;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        cout << i << "->";
        for(auto j: adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> dfstraversal = dfs(n, adj);
    cout << "DFS: ";
    for(auto i: dfstraversal){
        cout << i << " ";
    }

    return 0;
}
