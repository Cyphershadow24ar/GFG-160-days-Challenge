// Longest Palindromic Subsequence
// Difficulty: MediumAccuracy: 56.57%Submissions: 104K+Points: 4
// Given a string s, return the length of the longest palindromic subsequence.

// A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

// A palindromic sequence is a sequence that reads the same forward and backward.

// Examples:

// Input: s = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
// Input: s = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
// Input: s = "agbdba"
// Output: 5
// Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.
// Constraints:
// 1 ≤ s.size() ≤ 1000
// The string contains only lowercase letters.

// SOLUTION : 

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        
        for(int len = 2; len<=n; len++){
            for(int i = 0; i<=n-len; i++){
                int j = i + len-1;
                
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
