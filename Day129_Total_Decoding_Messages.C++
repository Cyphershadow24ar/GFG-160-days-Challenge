// PROBLEM : Total Decoding Messages

// A message containing letters A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// You are given a string digits. 
// You have to determine the total number of ways that message can be decoded.

// Examples:

// Input: digits = "123"
//Output: 3
// Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).

// Input: digits = "90"
// Output: 0
// Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.

// Input: digits = "05"
// Output: 0
// Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), 
// the string is not a valid encoding message.

// Constraints:
// 1 ≤ digits.size() ≤ 103

// SOLUTION : 

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        int n = digits.size();
        if( n == 0 || digits[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<= n; i++){
            if(digits[i-1] != '0'){
                dp[i] += dp[i-1];
            }
            int twoDigit = stoi(digits.substr(i-2,2));
            if(twoDigit >= 10 &&twoDigit <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

