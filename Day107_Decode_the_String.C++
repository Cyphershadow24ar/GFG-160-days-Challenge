// PROBLEM: Decode the string

// Given an encoded string s, the task is to decode it. The encoding rule is :
// k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "1[b]"
// Output: "b"
// Explanation: "b" is present only one time.

// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// 1. Inner substring “2[ca]” breakdown into “caca”.
// 2. Now, new string becomes “3[bcaca]”
// 3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.

// Constraints:
// 1 ≤ |s| ≤ 105 
// 1 <= k <= 100
// s contains only lowercase english alphabets

// SOLUTION: 

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> strStack;
        stack<int> countStack;
        string result = "";
        int mul = 0;
        
        for(char c : s){
            if(isdigit(c)){
                mul = mul*10 + (c-'0');
            }else if(c == '['){
                countStack.push(mul);
                strStack.push(result);
                mul= 0;
                result = "";
            }else if(c == ']'){
                int repeatCount = countStack.top();
                countStack.pop();
                string temp = result;
                while(--repeatCount){
                    result += temp;
                }
                result = strStack.top() + result;
                strStack.pop();
            }else{
                result += c;
            }
        }
        return result;
    }
};
