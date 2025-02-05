// PROBLEM: Construct Tree from Inorder & Preorder

// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

// Note: The output is written in postorder traversal.

// Examples:

// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]
// Explanation: The tree will look like

// Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [3, 4, 1, 5, 2, 0]
// Explanation: The tree will look like

// Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
// Output: [2, 5, 4, 3, 1]
// Explanation: The tree will look like

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 0 ≤ nodes -> data ≤ 103
// Both the inorder and preorder arrays contain unique values.

// SOLUITON :

class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;
    
    Node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int left, int right){
        if(left > right) return NULL;
        
        int rootvalue = preorder[preorderIndex++];
        Node* root = new Node(rootvalue);
        
        int inorderIndex = inorderMap[rootvalue];
        
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex+1, right);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        inorderMap.clear();
        preorderIndex = 0;
        
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size()-1);
    }
};
