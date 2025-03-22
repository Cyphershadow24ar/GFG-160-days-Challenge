// PROBLEM: Stickler Thief II

// You are given an array arr[] which represents houses arranged in a circle,
// where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
// Determine the maximum amount the thief can steal.

// Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

// Examples:

// Input: arr[] = [2, 3, 2]
// Output: 3
// Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.

// Input: arr[] = [1, 2, 3, 1]
// Output: 4
// Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4

// Input: arr[] = [2, 2, 3, 1, 2]
// Output: 5
// Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5

// Constraints:
// 2 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 104

// SOLUTION :

class Solution {
  public:
    int robHelper(vector<int>& arr, int start, int end){
        int prev1 = 0, prev2 =0;
        
        for(int i=start ; i<=end; i++){
            int pick = arr[i] + prev2;
            int notpick = prev1;
            
            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if( n ==1 ){
            return arr[0];
        }
        
        return max(robHelper(arr,0,n-2), robHelper(arr, 1, n-1));
    }
};
