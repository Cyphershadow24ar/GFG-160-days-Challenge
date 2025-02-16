// PROBLEM: Serialize and deserialize a binary tree

// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions
// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Examples :

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]

// Input: root = [10, 20, 30, 40, 60, N, N]
// Output: [40, 20, 60, 10, 30]

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 109

// SOLUTION :

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> res;
        if (!root) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node){
                res.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        if(arr.empty()) return NULL;
        
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i =1;
        
        while(!q.empty() && i < arr.size()){
            Node* node = q.front();
            q.pop();
            
            if(arr[i] != -1){
                node->left = new Node(arr[i]);
                q.push(node->left);
            }
            i++;
            
            if(i >= arr.size()) break;
            if(arr[i] != -1){
                node->right = new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
