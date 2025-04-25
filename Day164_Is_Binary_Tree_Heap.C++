// PROBLEM : Is Binary Tree Heap
 
// You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.
// A binary tree is considered a max-heap if it satisfies the following conditions:
// Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Max-Heap Property: The value of each node is greater than or equal to the values of its children.
    
// Examples:
    
// Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property. 

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
// Output: false
// Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 1 ≤ node->data ≤ 103

// SOLUTION : 

class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        if(!tree) return true;
        
        queue<Node*> q;
        q.push(tree);
        bool nullSeen = false;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->left){
                if(nullSeen || curr->data < curr->left->data) return false;
                q.push(curr->left);
            }else{
                nullSeen = true;
            }
            
            if(curr->right){
                if(nullSeen || curr->data < curr->right->data) return false;
                q.push(curr->right);
            }else{
                nullSeen = true;
            }
        }
        return true;
    }
};
