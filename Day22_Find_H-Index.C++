// QUESTION: Find H-Index

// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

// H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

// Examples:
// Input: citations[] = [3, 0, 5, 3, 0]
// Output: 3
// Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

// Input: citations[] = [5, 1, 2, 4, 1]
// Output: 2
// Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.

// Input: citations[] = [0, 0]
// Output: 0

// Constraints:
// 1 ≤ citations.size() ≤ 106
// 0 ≤ citations[i] ≤ 106

// SOLUTION: 

class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.rbegin(), citations.rend());
        
        int h_index = 0;
        for(int i=0; i<citations.size(); i++){
            if( citations[i] >= (i+1)){
                h_index = i+1; // for updating h-index
            }
            else{
                break; // to stop the loop when condtions is not met.
            }
        }
        return h_index;
    }
};

