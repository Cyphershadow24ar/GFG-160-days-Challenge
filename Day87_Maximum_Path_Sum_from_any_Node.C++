// PROBLEM: Maximum path sum from any node

// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Examples:

// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

// Input: root[] = [-17, 11, 4, 20, -2, 10]
// Output: 31
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

// Constraints:
// 1 ≤ number of nodes ≤ 103
// -104 ≤ node->data ≤ 104

// SOLUTION:

class Solution {
  public:
        int maxPathSumUtil(Node* node, int &res){
            if(node == NULL){
                return 0;
            }
            
            int leftMax = maxPathSumUtil(node->left, res);
            int rightMax = maxPathSumUtil(node->right, res);
            
            int max_single = max(max(node->data, node->data + leftMax), node->data + rightMax);
            int max_top = max(max_single, node->data + leftMax + rightMax);
            res = max(res, max_top);
            return max_single;
        }
         // Function to return maximum path sum from any node in a tree.
        int findMaxSum(Node *root){
            int res = INT_MIN;
            maxPathSumUtil(root, res);
            return res;
        }
};
