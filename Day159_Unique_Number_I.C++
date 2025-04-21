// PROBLEM: Unique Number I

// Given a unsorted array arr[] of positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

// Examples :

// Input: arr[] = [1, 2, 1, 5, 5]
// Output: 2
// Explanation: Since 2 occurs once, while other numbers occur twice, 2 is the answer.

// Input: arr[] = [2, 30, 2, 15, 20, 30, 15]
// Output: 20
// Explanation: Since 20 occurs once, while other numbers occur twice, 20 is the answer.

// Constraints
// 1 ≤  arr.size()  ≤ 106
// 0 ≤ arr[i] ≤ 109

// SOLUTION :

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int result = 0;
        for(int num : arr){
            result ^= num;
        }
        return result;
    }
};
