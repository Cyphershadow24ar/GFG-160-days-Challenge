// PROBLEM : Bridge edge in a graph

// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. 
// Determine whether a specific edge between two vertices (c, d) is a bridge.

// Note: An edge is called a bridge if removing it increases the number of connected components of the graph.
// if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.

// Examples :

// Input: c = 1, d = 2
// Output: true
// Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.
// Hence, it is a Bridge.

// Input:c = 0, d = 2
// Output: false
// Explanation: Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
// So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a blue line in the above image.

// Constraints:
// 1 ≤ V, E ≤ 105
// 0 ≤ c, d ≤ V-1

// SOULTION : 

class Solution {
  public:
    void dfs (int node, vector<bool> &visited, vector<int> adj[]){
        visited[node] = true;
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, visited, adj);
            }
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int> adj[V];
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        auto removeEdge = [&](int u, int v){
            adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        };
        
        removeEdge(c, d);
        removeEdge(d, c);
        
        vector<bool> visited(V, false);
        dfs(c, visited, adj);
        
        return !visited[d];
    }
};
