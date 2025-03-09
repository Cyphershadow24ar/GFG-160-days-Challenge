// PROBLEM: Palindrome SubStrings

// Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

// Examples

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings are : "aba" , "aa" , "baab".

// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings are : "aa", "aa", "aaa".

// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".

// Constraints:
// 2 ≤ s.size() ≤ 103
// string contains only lowercase english characters

// SOLUTION :

class Solution {
  public:
    void solve(string &s, int i,int j, int &count){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            if(j-i+1>=2)
                count++;
                i--;
                j++;
        }
    }
    
    int countPS(string &s) {
        // code here
        int n=s.size();
        int count =0;
        for(int i=0; i<n ;i++){
            solve(s,i,i,count);
            solve(s,i,i+1, count);
        }
        return count;
    }
};
