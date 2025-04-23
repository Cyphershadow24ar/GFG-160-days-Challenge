//  PROBLEM : Unique Number II

// Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas the other two number occur exactly once and are distinct.
// Find the other two numbers. Return the answer in increasing order.

// Examples:

// Input: arr[] = [1, 2, 3, 2, 1, 4]
// Output: [3, 4] 
// Explanation: 3 and 4 occur exactly once.

// Input: arr[] = [2, 1, 3, 2]
// Output: [1, 3]
// Explanation: 1 and 3 occur exactly once.

// Input: arr[] = [2, 1, 3, 3]
// Output: [1, 2]
// Explanation: 1 and 2 occur exactly once.

// Constraints:
// 2 ≤ arr.size() ≤ 106 
// 1 ≤ arr[i] ≤ 5 * 106
// arr.size() is even

// SOLUTION :

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int xor_all = 0;
        for(int num : arr){
            xor_all ^= num;
        }
        int set_bit = xor_all & -xor_all;
        
        int x = 0, y=0;
        for(int num : arr){
            if(num & set_bit)
                x ^= num;
            else
                y^=num;
        }
        
        if(x < y) return {x,y};
        else return {y,x};
    }
};
