/* PROBLEM :- Integer to Words

Difficulty: Medium Accuracy: 22.4% Submissions: 28K+Points: 4

Write a function to convert a given number n into words.
The idea is to break down the number into International Number System, i.e., smaller groups of three digits (hundreds, tens, and ones), and convert each group into words.

Examples :

Input: n = 0
Output: "Zero"

Input: n = 123
Output: "One Hundred Twenty Three"

Input: n = 10245
Output: "Ten Thousand Two Hundred Forty Five"

Input: n = 2147483647
Output: "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven"

Constraints:
0 <= n <= 231-1 */

// SOLUTION :-

// User function template for C++

class Solution {
  public:
    vector<string> below_20 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
        "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen",
        "Eighteen","Nineteen"};
        
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty","Seventy", "Eighty", "Ninety"};
    
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    string helper(int num){
        if(num == 0) return "";
        else if (num < 20) return below_20[num] + " ";
        else if (num < 100) return tens[num/10] + " " + helper(num % 10);
        else return below_20[num/100] + " Hundred " + helper(num % 100);
    }
    string convertToWords(int n) {
        // code here
        if(n == 0) return "Zero";
        
        string result;
        int idx =0;
        
        while( n > 0){
            int chunk = n% 1000;
            if(chunk != 0){
                string chunkStr = helper(chunk) + (thousands[idx] != "" ? thousands[idx] + " " : "");
                result = chunkStr + result;
            }
            n /= 1000;
            idx++;
        }
        while(!result.empty() && result.back() == ' ')
            result.pop_back();
            
        return result;
    }
};
