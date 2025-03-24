// PROBLEM: Boolean Parenthesization

// You are given a boolean expression s containing
//     'T' ---> true
//     'F' ---> false 
// and following operators between symbols
//    &   ---> boolean AND
//     |   ---> boolean OR
//    ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer is guaranteed to fit within a 32-bit integer.

// Examples:

// Input: s = "T|T&F^T"
// Output: 4
// Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// Input: s = "T^F|F"
// Output: 2
// Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).

// Constraints:
// 1 ≤ |s| ≤ 100 

// SOLUTION :

class Solution {
  public:
    unordered_map<string, int> dp;
    
    int solve(string &s, int i, int j, bool isTrue){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if(dp.find(key) != dp.end()) return dp[key];
        
        int ways= 0;
        for(int k = i+1; k <j; k+= 2){
            int leftTrue = solve(s, i, k-1, true);
            int leftFalse = solve(s, i, k-1, false);
            int rightTrue = solve(s, k+1, j, true);
            int rightFalse = solve(s, k+1, j, false);
            
            if(s[k] == '&'){
                if(isTrue) ways += leftTrue * rightTrue;
                else ways += leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse;
            }
            
            else if(s[k] == '|'){
                if(isTrue) ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftFalse * rightFalse;
            }
            
            else if(s[k] == '^'){
                if(isTrue) ways += leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftTrue * rightTrue +leftFalse * rightFalse;
            }
        }
        return dp[key] = ways;
    }
    int countWays(string &s) {
        // code here
        dp.clear();
        return solve(s, 0, s.size()-1, true);
    }
};
