// PROBLEM: Find Only Repetitive Element from 1 to n-1

// Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. 
// The array has only one repetitive element. Your task is to find the repetitive element.

// Note: It is guaranteed that there is a repeating element present in the array.

// Examples:

// Input: arr[] = [1, 3, 2, 3, 4]
// Output: 3 
// Explanation: The number 3 is the only repeating element.

// Input: arr[] = [1, 5, 1, 2, 3, 4]
// Output: 1  
// Explanation: The number 1 is the only repeating element.

// Input: arr[] = [1, 1]  
// Output: 1
// Explanation: The array is of size 2 with both elements being 1, making 1 the repeating element.

// Constraints:
// 2 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ n-1 

// SOLUTION : 

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int slow = arr[0];
        int fast = arr[0];
        
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while (slow != fast);
        
        slow = arr[0];
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return slow;
    }
};
