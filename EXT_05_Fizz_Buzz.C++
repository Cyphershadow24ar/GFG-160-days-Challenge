/* PROBLEM - (Strings) Fizz Buzz
Difficulty: EasyAccuracy: 67.48%Submissions: 6K+Points: 2
Fizz Buzz Problem involves that given an integer n, for every integer 0 < i <= n, the task is to output,

"FizzBuzz" if i is divisible by 3 and 5,
"Fizz" if i is divisible by 3,
"Buzz" if i is divisible by 5
"i" as a string, if none of the conditions are true.
Return an array of strings.

Examples :

Input: n = 3
Output: ["1", "2", "Fizz"]
Explanation: 1 and 2 are neither divisible by 3 nor 5, so we just output 1 and 2, and 3 is divisible by 3 so we output "Fizz".
Input: n = 10
Output: ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz"]
Input: n = 20
Output: [“1”, “2”, “Fizz”, “4”, “Buzz”, “Fizz”, “7”, “8”, “Fizz”, “Buzz”, “11”, “Fizz”, “13”, “14”, “FizzBuzz”, “16”, “17”, “Fizz”, “19”, “Buzz”]
Constraints:
1 ≤ n ≤ 10 */

// SOLUTION :-


class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        // code here
        vector<string> result;
        
        for(int i =1; i<=n; ++i){
            if(i % 3 == 0 && i % 5 == 0)
                result.push_back("FizzBuzz");
            else if(i % 3 == 0)
                result.push_back("Fizz");
            else if(i % 5 == 0)
                result.push_back("Buzz");
            else
                result.push_back(to_string(i));
        }
        return result;
    }
};
