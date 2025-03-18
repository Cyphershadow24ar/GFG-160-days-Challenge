// PROBLEM: Partition Equal Subset Sum

// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
// Note: Each element must be in exactly one subset.

// Examples:

// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].

// Input: arr = [1, 3, 5]
// Output: false
// Explanation: This array can never be partitioned into two such parts.

// Constraints:
// 1 ≤ arr.size ≤ 100
// 1 ≤ arr[i] ≤ 200

// SOLUTION : 

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int num : arr){
            for(int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
