// PROBLEM : Minimum Weight Cycle

// Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
// Your task is to find the minimum weight cycle in this graph.

// Examples:

// Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]
// Output: 6
// Explanation: Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)

// Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]
// Output: 5
// Explanation: Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)

// Constraints:
// 1 ≤ V ≤ 100
// 1 ≤ E = edges.size() ≤ 103 
// 1 ≤ edges[i][j] ≤ 100

// SOLUTION : 

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        int ans = INT_MAX;
        
        map<int, vector<pair<int, int>>>adjList;
        
        for(auto i : edges){
            int u = i[0], v = i[1], w = i[2];
            
            adjList[u].push_back({v, w});
            adjList[V].push_back({u, w});
        }
        
        for(auto i : edges){
            int src = i[0], dest =i[1], wt = i[2];
            
            vector<int>dist(V, INT_MAX);
            dist[src] = 0;
            set<pair<int, int>>s;
            s.insert({0, src});
            
            while(!s.empty()){
                pair<int, int>p = *(s.begin());
                int topDist = p.first;
                int topNode = p.second;
                
                s.erase(s.begin());
                
                for(auto nbr : adjList[topNode]){
                    int currNode = nbr.first, currWt = nbr.second;
                    
                    if(topNode == src && currNode == dest) continue;
                    
                    if(dist[currNode] > topDist + currWt){
                        if(s.find({dist[currNode], currNode}) != s.end()) s.erase({dist[currNode], currNode});
                        dist[currNode] = topDist + currWt;
                        if(currNode != dest) s.insert({dist[currNode],currNode});
                    }
                }
            }
            if(dist[dest] != INT_MAX) ans = min(ans, dist[dest] + wt);
        }
        return ans;
    }
};
