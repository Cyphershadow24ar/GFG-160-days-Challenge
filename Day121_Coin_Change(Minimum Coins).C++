// PROBLEM: Coin Change (Minimum Coins)

// You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. 
// You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.
// Your task is to determine the minimum number of coins needed to obtain the target sum. 
// If it is not possible to form the sum using the given coins, return -1.

// Examples:

// Input: coins[] = [25, 10, 5], sum = 30
// Output: 2
// Explanation: Minimum 2 coins needed, 25 and 5  

// Input: coins[] = [9, 6, 5, 1], sum = 19
// Output: 3
// Explanation: 19 = 9 + 9 + 1

// Input: coins[] = [5, 1], sum = 0
// Output: 0
// Explanation: For 0 sum, we do not need a coin

// Input: coins[] = [4, 6, 2], sum = 5
// Output: -1
// Explanation: Not possible to make the given sum.
 
// Constraints:
// 1 ≤ sum * coins.size() ≤ 106
// 0 <= sum <= 104
// 1 <= coins[i] <= 104
// 1 <= coins.size() <= 103

// SOLUTION :

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        
        for(int coin: coins){
            for(int j = coin; j <= sum; j++){
                if(dp[j - coin] != INT_MAX){
                    dp[j] = min(dp[j], 1 + dp[j - coin]);
                }
            }
        }
        return (dp[sum] == INT_MAX) ? -1 : dp[sum];
    }
};
