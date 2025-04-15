// PROBLEM : Bellman-Ford

// Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.
// Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

// Examples:

// Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
// Output: [0, 5, 6, 6, 7]
// Explanation: Shortest Paths:
// For 0 to 1 minimum distance will be 5. By following path 0 → 1
// For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
// For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
// For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4

// Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
// Output: [-1]
// Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.

// Constraints:
// 1 ≤ V ≤ 100
// 1 ≤ E = edges.size() ≤ V*(V-1)
// -1000 ≤ w ≤ 1000
// 0 ≤ src < V

// SOLUTION : 

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int INF = 1e8;
        vector<int> dist(V, INF);
        dist[src] = 0;
        
        for(int i=0; i<V-1; ++i){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] != INF && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for(auto &edge :  edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INF && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};

