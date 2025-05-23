// PROBLEM: Articulation Point - II

// You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
// Your task is to return all the articulation points (or cut vertices) in the graph.
// An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

// Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
// If no such point exists, return {-1}.

// Examples :

// Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]
// Output: [1, 4]
//Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
// Input: V = 4, edges[][] = [[0, 1], [0, 2]]
// Output: [0]
// Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  

// Constraints:
// 1 ≤ V, E ≤ 104

// SOLUTION :

class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<bool>& isArticulation, int& timer  ){
        visited[u] = true;
        tin[u] = low[u]= timer++;
        int children = 0;
        
        for(int v : adj[u]){
            if(v == parent) continue;
            
            if(!visited[v]){
                dfs(v, u, adj, tin, low, visited, isArticulation, timer);
                low[u] = min(low[u], low[v]);
                
                if(low[v] >=tin[u] && parent != -1)
                    isArticulation[u] = true;
                    
                ++children;
            }else{
                low[u] = min(low[u], tin[v]);
            }
        }
        if(parent == -1 && children > 1){
            isArticulation[u] = true;
        }
    }
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> tin(V, -1), low(V, -1);
        vector<bool> visited(V, false), isArticulation(V, false);
        int timer = 0;
        
        for(int i =0; i<V ; i++){
            if(!visited[i]){
                dfs(i, -1, adj, tin, low, visited, isArticulation, timer);
            }
        }
        vector<int> result;
        for(int i =0; i<V; i++){
            if(isArticulation[i]){
                result.push_back(i);
            }
        }
        
        if(result.empty()) return{-1};
        return result;
    }
};
