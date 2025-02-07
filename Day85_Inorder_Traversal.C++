// PROBLEM: Inorder Traversal
// Given a Binary Tree, your task is to return its In-Order Traversal.
// An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

// Examples:

// Input: root[] = [1, 2, 3, 4, 5] 
// Output: [4, 2, 5, 1, 3]
// Explanation: The in-order traversal of the given binary tree is [4, 2, 5, 1, 3].

// Input: root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]   
// Output: [1, 7, 10, 8, 6, 10, 5, 6]
// Explanation: The in-order traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].

// Constraints:
// 1 <= number of nodes <= 105
// 0 <= node->data <= 105

// SOLUITON :


class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
  private:
    void inorderTraversal(Node* node, vector<int>& result){
        if(node == NULL) return;
        
        inorderTraversal(node->left, result);// for visiting left subtree
        result.push_back(node->data); // for visiting current node
        inorderTraversal(node->right, result); // for visiting right subtree
    }
      
};
