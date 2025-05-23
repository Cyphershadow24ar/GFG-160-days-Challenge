# QUESTION: Kth Missing Positive Number in a Sorted Array

# Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  

# Examples :

# Input: arr[] = [2, 3, 4, 7, 11], k = 5
# Output: 9
# Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.

# Input: arr[] = [1, 2, 3], k = 2
# Output: 5
# Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.

# Input: arr[] = [3, 5, 9, 10, 11, 12], k = 2
# Output: 2
# Explanation: Missing are 1, 2, 4, 5, 6… and 2nd missing number is 2.

# Constraints:
# 1 <= arr.size() <= 105
# 1 <= k <= 105
# 1 <= arr[i]<= 106

# SOLUTION: 

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        int prev = 0; // To Tracks the last observed number

        for (int i = 0; i < n; i++) {
            int missing_num = arr[i] - prev - 1;
            if (k <= missing_num) {
                return prev + k;
            }
            k -= missing_num;
            prev = arr[i];
        }
        return arr[n-1] + k;
    }
};
