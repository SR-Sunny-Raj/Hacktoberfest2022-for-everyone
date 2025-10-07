#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int src, vector<bool>& visited, vector<bool>& pathvis, vector<vector<int>>& adj) {
    visited[src] = true;
    pathvis[src] = true;
    for (int neighbor : adj[src]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, visited, pathvis, adj)) return true;
        } else if (pathvis[neighbor]) {
            return true;  
        }
    }
    pathvis[src]=false;
    return false;
}
// Toposort can be also used for cycle detection in DAG.(If final toposeq doesnt contains all nodes then cycle present)

int main() {
    int e, n; 
    cout << "Enter No of edges and Vertices: ";
    cin >> e >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n, false);
    vector<bool> pathvis(n, false);
    bool cycleFound = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, visited, pathvis, adj)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound)
        cout << "Cycle detected using DFS" << endl;
    else
        cout << "Cycle not detected using DFS" << endl;

    return 0;
}
