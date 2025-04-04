// PROBLEM : Undirected Graph Cycle

// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][],
// where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 1 -> 2 -> 0 -> 1 is a cycle.

// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation: No cycle in the graph.

// Constraints:
// 1 ≤ V ≤ 105
// 1 ≤ E = edges.size() ≤ 105

// SOLUTION : 

class Solution {
  public:
    int find(int x, vector<int>& parent){
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    void unionSet(int u, int v, vector<int>& parent){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu != pv){
            parent[pu] = pv;
        }
    }
    
    bool isCycle(int v, vector<vector<int>>& edges) {
        // Code here
        vector<int> parent(v);
        for(int i=0; i<v; ++i)
            parent[i] = i;
    
        for(auto& edge : edges){
            int u = edge[0];
            int vtx = edge[1];
            int pu = find(u, parent);
            int pv = find(v, parent);
            
            if(pu == pv)
                return true;
            unionSet(pu, pv, parent);
        }
        return false;
    }
};
