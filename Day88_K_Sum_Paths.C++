// PROBLEM: K Sum Paths

// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k.
// A path can start and end at any node within the tree but must always move downward (from parent to child).

// Examples:
// Input: k = 7   
// Output: 3
// Explanation: The following paths sum to k 
 
// Input: k = 3
//    1
//  /  \
// 2     3
// Output: 2
// Explanation:
// Path 1 : 1 -> 2 (Sum = 3)
// Path 2 : 3 (Sum = 3)

// Constraints:
// 1 ≤ number of nodes ≤ 104
// -100 ≤ node value ≤ 100
// -109 ≤ k ≤ 109

// SOLUTION: 

class Solution {
  public:
    void solve(Node* root, int k, long long currentSum, unordered_map<long long, int>& prefixSum, int& count){
        if(!root) return;
        
        currentSum += root->data;
        
        if(currentSum == k) count++;
        
        if(prefixSum.find(currentSum - k) != prefixSum.end()){
            count += prefixSum[currentSum - k];
        }
        
        prefixSum[currentSum]++;
        
        solve(root->left, k, currentSum, prefixSum, count);
        solve(root->right, k, currentSum, prefixSum, count);
        
        prefixSum[currentSum]--;
    }
    
    int sumK(Node *root, int k) {
        // code here
        unordered_map<long long, int> prefixSum;
        int count =0;
        solve(root, k, 0, prefixSum, count);
        return count;
    }
};
