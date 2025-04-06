// PROBLEM: Topological sort

// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes an directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]

// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]
// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]

// Constraints:
// 2  ≤  V  ≤  103
// 1  ≤  E = edges.size()  ≤  (V * (V - 1)) / 2

// SOLUTION : 

class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[v];
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> indegree(v, 0);
        for(int i=0; i<v ; i++){
            for(int v : adj[i]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i =0; i<v ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return topo;
    }
};class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[v];
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> indegree(v, 0);
        for(int i=0; i<v ; i++){
            for(int v : adj[i]){
                indegree[v];
            }
        }
        
        queue<int> q;
        for(int i =0; i<v ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return topo;
    }
};
