#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 500;
/*
   Adjacency List
   edge = {u, v, w}
   g[u].push_back({v, w})
*/
vector <pair<int, int>> G[M];

vector <int> bellmanFord(int &N, vector <vector<int>> edges){
   /*
       Step 1 - Add a new vertex 0 to the given graph, add edges of  
       weight 0 from the new vertex to all the existing vertices.
       edge = {0, u, 0} (1 <= u <= N)
   */
   for(int i = 1; i <= N; i++){
       edges.push_back({0, i, 0});
   }
   /*
       Step 2 - Find the shortest path from the new vertex to all the other 
       existing vertices using the Bellman-Ford algorithm.
   */
   vector <int> d(N + 1, INT_MAX);
   d[0] = 0;
   while(true){
       bool check = false;
       for(auto e : edges){
           int u = e[0];
           int v = e[1];
           int w = e[2];
           if(d[v] > d[u] + w){
               d[v] = d[u] + w;
               check = true;
           }
       }
       if(!check)
           break;
   }
   //The shortest distance values are values of c[].
   return d;
}

//Dijkstra Algorithm
void Dijkstra(int src, vector <vector<int>> &path, int &N){
   
   priority_queue<pair<int, int>> pq;
   vector <int> vis(N + 1);
   path[src][src] = 0;
   pq.push({0, src});
   while(!pq.empty()){
       int f = pq.top().second;
       pq.pop();
       if(!vis[f]){
           vis[f] = true;
           for(auto u : G[f]){
               int s = u.first;
               int w = u.second;
               if(path[src][f] + w < path[src][s]){
                   path[src][s] = path[src][f] + w;
                   pq.push({-path[src][s], s});
               }
           }
       }
   }
}

signed main(){
   //vertices, edges
   int N, M;
   cin >> N >> M;
   /*
       vector to store edges
       edge - (u->v)
       weight - w
       edges.push_back({u, v, w})
   */
   vector <vector<int>> edges;
   for(int i = 1; i <= M; i++){
       int u, v, w;
       cin >> u >> v >> w;
       edges.push_back({u, v, w});
   }
   //The shortest distance values are values of c[].
   vector <int> C = bellmanFord(N, edges);
   for(int i = 0; i < M; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       //For every pair of vertices u and v, having an edge (u -> v), add C[u] - C[v] to the edge weight.
       edges[i][2] += (C[u] - C[v]);
   }
   /*
       2D matrix to store all-pairs shortest path
       path[u][v] = shortest path from u to v
   */
   vector <vector<int>> path(N + 1, vector <int> (N + 1, INT_MAX));
   
   for(auto e : edges){
       G[e[0]].push_back({e[1], e[2]});
   }
   /*
   Step 4 - Remove the added vertex (vertex 0) and apply Dijkstra's algorithm for every vertex.
   */
   for(int i = 1; i <= N; i++){
       Dijkstra(i, path, N);
   }
   for(int i = 1; i <= N; i++){
       for(int j = 1; j <= N; j++){
           //If there is no path between i and j output -1
           if(path[i][j] == INT_MAX)
               cout << -1 << " ";
           //shortest path from vertex i to j
           else
               cout << path[i][j] - (C[i] - C[j]) << " ";
       }
       cout << "\n";
   }
   return 0;
}   
