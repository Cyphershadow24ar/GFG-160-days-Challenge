// PROBLEM: Pair with given sum in a sorted array

// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
// Note: pairs should have elements of distinct indexes. 

// Examples :

// Input: arr[] = [-1, 1, 5, 5, 7], target = 6
// Output: 3
// Explanation: There are 2 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.

// Input: arr[] = [1, 1, 1, 1], target = 2
// Output: 6
// Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.

// Input: arr[] = [-1, 10, 10, 12, 15], target = 125
// Output: 0
// Explanation: There is no such pair which sums up to 4.

// Constraints:
// -105 <= target <=105
//  2 <= arr.size() <= 105
// -105 <= arr[i] <= 105


// SOLUTION: 

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int count =0;
        unordered_map<int, int>mp;
         
        for(int i=0; i<n; i++){
            int com = target - arr[i];
            if(mp.find(com) !=mp.end()){
                count +=mp[com];
            }
            mp[arr[i]]++;
        }
        return count;
    }
};
