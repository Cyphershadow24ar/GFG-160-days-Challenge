// PROBLEM : Multiply two strings

// Given two numbers as strings s1 and s2. Calculate their Product.
// Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. 
// There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

// Examples:

// Input: s1 = "0033", s2 = "2"
// Output: "66"
// Explanation: 33 * 2 = 66

// Input: s1 = "11", s2 = "23"
// Output: "253"
// Explanation: 11 * 23  = 253

// Input: s1 = "123", s2 = "0"
// Output: "0"
// Explanation: Anything multiplied by 0 is equal to 0.

// Constraints:
// 1 ≤ s1.size() ≤ 103
// 1 ≤ s2.size() ≤ 103

// SOLUTION :

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        bool negative = false;
        if(s1[0] == '-'){
            negative = !negative;
            s1 = s1.substr(1);
        }
        if(s2[0] == '-'){
            negative = !negative;
            s2 = s2.substr(1);
        }
        
        while(s1.size() > 1 && s1[0] == '0') s1.erase(0,1);
        while(s2.size() > 1 && s2[0] == '0') s2.erase(0,1);
        
        if(s1 == "0" || s2 == "0") return "0";
        
        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j = m-1; j >= 0; j--){
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i +j] += sum/10;
                result[i + j + 1] = sum%10;
            }
        }
        
        string res ="";
        int i=0;
        while(i < result.size() && result[i] == 0)i++;
        while(i < result.size()){
            res += result[i++] + '0';
        }
        if (negative) res = '-' + res;
        return res; 
    }
};
