// PROBLEM: Pair Sum in BST

// Given a Binary Search Tree(BST) and a target. 
// Check whether there's a pair of Nodes in the BST with value summing up to the target. 

// Examples:

// Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
// Output: True
// Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.

// Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
// Output: False
// Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.

// Constraints:
// 1 ≤ Number of Nodes ≤ 105
// 1 ≤ target ≤ 106

// SOLUTION: 

class Solution {
  public:
    void inorder(Node* root, vector<int>& vals){
        if(!root) return;
        inorder(root->left, vals);
        vals.push_back(root->data);
        inorder(root->right, vals);
    }
    
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> vals;
        inorder(root, vals);
        
        int left = 0, right = vals.size()-1;
        while(left<right){
            int sum = vals[left] + vals[right];
            if(sum == target){
                return true;
            }
            else if(sum <target){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};
