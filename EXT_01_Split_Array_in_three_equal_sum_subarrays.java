/* Split array in three equal sum subarrays
Difficulty: MediumAccuracy: 52.9%Submissions: 29K+Points: 4
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4, so driver code prints true.
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106 */

// SOLUTION :- IN JAVA

// User function Template for Java
class Solution {

    public List<Integer> findSplit(int[] arr) {
        // Return an array of possible answer, driver code will judge and return true or
        // false based on
        int n = arr.length;
        long totalSum = 0;
        
        for(int num : arr) totalSum += num;
        
        if(totalSum % 3 != 0) return Arrays.asList(-1, -1);
        
        long target = totalSum / 3;
        long currSum = 0;
        int first = -1, second = -1;
        
        for(int i =0; i<n ; i++){
            currSum += arr[i];
            if(currSum == target && first == -1){
                first = i;
            }else if(currSum == 2 * target && first != -1){
                second = i;
                break;
            }
        }
        if(first != -1 && second != -1 && second < n-1){
            return Arrays.asList(first, second);
        }
        
        return Arrays.asList(-1, -1);
    }
    

// User function Template for Java
class SplitarrayinthreeEqualsumSubarrays {

    public List<Integer> findSplit(int[] arr) {
        // Return an array of possible answer, driver code will judge and return true or
        // false based on
        int n = arr.length;
        long totalSum = 0;
        
        for(int num : arr) totalSum += num;
        
        if(totalSum % 3 != 0) return Arrays.asList(-1, -1);
        
        long target = totalSum / 3;
        long currSum = 0;
        int first = -1, second = -1;
        
        for(int i =0; i<n ; i++){
            currSum += arr[i];
            if(currSum == target && first == -1){
                first = i;
            }else if(currSum == 2 * target && first != -1){
                second = i;
                break;
            }
        }
        if(first != -1 && second != -1 && second < n-1){
            return Arrays.asList(first, second);
        }
        
        return Arrays.asList(-1, -1);
    }
    
}
