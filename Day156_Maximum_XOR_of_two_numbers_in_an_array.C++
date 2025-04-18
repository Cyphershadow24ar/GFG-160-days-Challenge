// PROBLEM : Maximum XOR of two numbers in an array

// Given an array arr[] of non-negative integers of size n. 
// Find the maximum possible XOR between two numbers present in the array.

// Examples:

// Input: arr[] = [25, 10, 2, 8, 5, 3]
// Output: 28
// Explanation: The maximum possible XOR is 5 ^ 25 = 28.

// Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
// Output: 7
// Explanation : The maximum possible XOR is 1 ^ 6 = 7.

// Constraints:
// 2 ≤ arr.size() ≤ 5*104
// 1 ≤ arr[i] ≤ 106

// SOLUTION : 

class TrieNode {
  public:
    TrieNode* next[2];
    TrieNode() {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class Solution {
    TrieNode* root = new TrieNode();
    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            if(!node-> next[bit]){
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }
    
    int findMaxXor(int num){
        TrieNode* node = root;
        int maxXor = 0;
        for(int i =31; i>=0; --i){
            int bit = (num >> i) & 1;
            int opp = 1 - bit;
            if(node->next[opp]){
                maxXor |= (1 << i);
                node = node->next[opp];
            }else{
                node = node->next[bit];
            }
        }
        return maxXor;
    }
    
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int result = 0;
        for(int num : arr){
            insert(num);
        }
        for(int num : arr){
            result = max(result, findMaxXor(num));
        }
        return result;
    }
};
