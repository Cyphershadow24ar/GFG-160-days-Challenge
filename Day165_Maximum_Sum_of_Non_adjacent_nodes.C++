// PROBLEM :Maximum sum of Non-adjacent nodes

// Given a binary tree with a value associated with each node. 
// Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root[] = [11, 1, 2]
// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.

// Input: root[] = [1, 2, 3, 4, N, 5, 6]
// Output: 16
// Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

// Constraints:
// 1 ≤ no. of nodes in the tree ≤ 104
// 1 ≤ Node.val ≤ 105

// SOLUTION :

class Solution {
  public:
    pair<int, int> solve(Node* root){
        if(!root) return {0, 0};
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        int include = root->data + left.second + right.second;
        
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return{include, exclude};
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
