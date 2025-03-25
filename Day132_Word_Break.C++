// PROBLEM: Word Break

// You are given a string s and a list dictionary[] of words. 
// Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

// Note: From dictionary[], any word can be taken any number of times and in any order.

// Examples :

// Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like".

// Input: s = "ilikegfg", dictionary = ["i", "like", "man", "india", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like gfg".

// Input: s = "ilikemangoes", dictionary = ["i", "like", "man", "india", "gfg"]
// Output: false
// Explanation: s cannot be formed using dictionary[] words.

// Constraints:
// 1 ≤ s.size() ≤ 3000
// 1 ≤ dictionary.size() ≤ 1000
// 1 ≤ dictionary[i].size() ≤ 100

// SOLUTION :

class Solution {
  public:
    int wordBreak(string &s, vector<string> &dictionary) {
        // code here
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i =1; i<=n ; i++){
            for(int j =0; j < i; j++){
                if(dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
