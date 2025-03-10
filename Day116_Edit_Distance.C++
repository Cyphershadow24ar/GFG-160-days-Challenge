// PROBLEM:  Edit Distance

// Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
// The possible operations are permitted:
// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

// Examples:

// Input: s1 = "geek", s2 = "gesek"
// Output: 1
// Explanation: One operation is required, inserting 's' between two 'e' in s1.

// Input: s1 = "gfg", s2 = "gfg"
// Output: 0
// Explanation: Both strings are same.

// Input: s1 = "abcd", s2 = "bcfe"
// Output: 3
// Explanation: We can convert s1 into s2 by removing ‘a’, replacing ‘d’ with ‘f’ and inserting ‘e’ at the end. 

// Constraints:
// 1 ≤ s1.length(), s2.length() ≤ 103
// Both the strings are in lowercase.

// Solution : 

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int m = s1.length(), n=s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<=m ; i++) dp[i][0] = i;
        for(int j=0; j <=n ; j++) dp[0][j] = j;
        
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<= n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};
