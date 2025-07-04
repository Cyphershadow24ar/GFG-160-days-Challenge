/* PROBLEM:- Maximize Number of 1's

Given a binary array arr[] (containing only 0s and 1s) and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

Examples:

Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: Maximum subarray of consecutive 1's is of size 3 which can be obtained after flipping the zero present at the 1st index.

Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray  from index 3 to 7 containing all 1’s.

Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2

Constraints:
1 <= arr.size() <= 105
0 <= k <= arr.size()
0 <= arr[i] <= 1
 */

// SOLUTION : 

// User function Template for Java

class Solution {
    // k is the maximum number of zeros allowed to flip
    public int maxOnes(int arr[], int k) {
        // code here
        int left = 0, right =0;
        int maxLen = 0;
        int zeroCount = 0;
        
        while(right < arr.length){
            if(arr[right] == 0){
                zeroCount++;
            }
            
            while(zeroCount > k){
                if(arr[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
}
