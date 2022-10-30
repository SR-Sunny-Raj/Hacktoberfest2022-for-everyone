#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[]);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        cout << i << "->";
        for(auto j: adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> bfstraversal = bfs(n, adj);
    cout << "BFS: ";
    for(auto i: bfstraversal) {
        cout << i << " ";
    }

    return 0;
}

vector<int> bfs(int n, vector<int> adj[]) {
    vector<int> bfstraversal;
    vector<int> visited(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfstraversal.push_back(node);
                for(auto it: adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfstraversal;
}
