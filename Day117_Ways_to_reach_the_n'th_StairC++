
//PROBLEM:  Ways to Reach the n'th Stair

// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. 
// Your task is to count the number of ways, the person can reach the top (order does matter).

// Examples:

// Input: n = 1
// Output: 1
// Explanation: There is only one way to climb 1 stair. 

// Input: n = 2
// Output: 2
// Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}. 

// Input: n = 4
// Output: 5
// Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.

// Constraints:
// 1 ≤ n ≤ 44

// SOLUTION : 

class Solution {
  public:
    int countWays(int n) {
        // your code here
            if(n == 1) return 1;
            if(n == 2) return 2;
            
            int prev2 =1, prev1 = 2, curr;
            for(int i =3; i<=n; i++){
                curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
            }
            return curr;
    }
}
