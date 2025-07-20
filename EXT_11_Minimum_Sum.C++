/* PROBLEM :- Minimum sum

Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. 
Return the minimum possible sum as a string with no leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.

Input: arr[] = [5, 3, 0, 7, 4]
Output: "82"
Explanation: The minimum sum is formed by numbers 35 and 047.

Input: arr[] = [9, 4]
Output: "13"
Explanation: The minimum sum is formed by numbers 9 and 4.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9
*/

// SOLUTION :-

class Solution {
  public:
    string addStrings(string a, string b){
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string result;
        
        while( i >= 0 || j >= 0|| carry){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            result.push_back((sum % 10) + '0');
            carry = sum/10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        string num1, num2;
        for(int i=0; i<arr.size(); i++){
            if(i % 2 == 0) num1.push_back(arr[i] + '0');
            else num2.push_back(arr[i] + '0');
        }
        
        string sum = addStrings(num1,num2);
        
        int pos = 0;
        while(pos < sum.size() - 1 && sum[pos] == '0') pos++;
        return sum.substr(pos);
        
    }
};
