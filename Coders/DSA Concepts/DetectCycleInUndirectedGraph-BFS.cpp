// Function to detect cycle in an undirected graph.
bool isCycle(int n, vector<int> adj[]) {
    // using bfs
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            queue<pair<int,int>> q;
            q.push({i, -1});
            while(!q.empty()){
                auto f=q.front();
                q.pop();
                vis[f.first]=1;
                for(int &nbr: adj[f.first]){
                    if(nbr!=f.second && vis[nbr])
                        return true;
                    if(!vis[nbr])
                        q.push({nbr, f.first});
                }
            }
        }
    }
    return false;
}

/*
Time Complexity: O(n+v)
Space Complexity: O(n+v)
*/
