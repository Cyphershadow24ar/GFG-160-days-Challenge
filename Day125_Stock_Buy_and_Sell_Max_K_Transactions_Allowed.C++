// PROBLEM: Stock Buy and Sell – Max K Transactions Allowed

// In the stock market, a person buys a stock and sells it on some future date. 
// You are given an array prices[] representing stock prices on different days and a positive integer k, find out the maximum profit a person can make in at-most k transactions.
// A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.

// Examples :

// Input: prices[] = [10, 22, 5, 80], k = 2
// Output: 87
// Explaination:
// 1st transaction: Buy at 10 and sell at 22. 
// 2nd transaction : Buy at 5 and sell at 80.
// Total Profit will be 12 + 75 = 87.

// Input: prices[] = [20, 580, 420, 900], k = 3
// Output: 1040
// Explaination: 
// 1st transaction: Buy at 20 and sell at 580. 
// 2nd transaction : Buy at 420 and sell at 900.
// Total Profit will be 560 + 480 = 1040.

// Input: prices[] = [100, 90, 80, 50, 25],  k = 1
// Output: 0
// Explaination: Selling price is decreasing continuously
// leading to loss. So seller cannot have any profit.

// Constraints:
// 1 ≤ prices.size() ≤ 103
// 1 ≤ k ≤ 200
// 1 ≤ prices[i] ≤ 103

// SOLUTION :

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        if(n == 0 || k == 0) return 0;
        
        if(k >= n/2){
            int profit = 0;
            for(int i=1; i<n ; i++){
                if(prices[i] > prices[i -1]){
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
            
            vector<vector<int>> dp(k + 1, vector<int>(n,0));
            
            for(int i = 1; i<=k; i++){
                int maxDiff = -prices[0];
                for(int j =1; j<n ; j++){
                    dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
                    maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
                }
            }
        return dp[k][n-1];
    }
};
