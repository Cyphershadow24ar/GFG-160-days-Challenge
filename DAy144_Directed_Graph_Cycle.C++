// PORBLEM : Directed Graph Cycle

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
// Output: true
// Explanation: 3 -> 3 is a cycle

// Input: V = 3, edges[][] = [[0, 1], [1, 2]]
// Output: false
// Explanation: no cycle in the graph

// Constraints:
// 1 ≤ V, E ≤ 105

// SOLUTION :

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack){
        visited[node] = true;
        recStack[node] = true;
        
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,adj,visited, recStack))
                    return true;
            }else if(recStack[neighbor]){
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        for(int i = 0; i<V ; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};
