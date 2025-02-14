// PROBLEM: Fixing Two nodes of a BST

// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).
 
// Examples :

// Input: root = [10, 5, 8, 2, 20]
// Output: 1
// Explanation: The nodes 20 and 8 were swapped. 

// Input: root = [5, 10, 20, 2, 8]     
// Output: 1 
// Explanation: The nodes 10 and 5 were swapped.

// Constraints:
// 1 ≤ Number of nodes ≤ 103

// SOLUTION: 

class Solution {
  public:
    Node*first, *middle, *last, *prev;
    
    void inorderTraversal(Node* root){
        if(!root) return;
        
        inorderTraversal(root->left);
        
        if(prev && root->data < prev->data){
            if(!first){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorderTraversal(root->right);
    }
    void correctBST(Node* root) {
        // add code here.
        first = middle = last = prev = NULL;
        
        inorderTraversal(root);
        
        if(first && last){
            swap(first->data, last->data);
        }else if(first && middle){
            swap (first->data, middle->data);
        }
    }
};
