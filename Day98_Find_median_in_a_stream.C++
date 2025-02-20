// PROBLEM: Find median in a stream

// Given a data stream arr[] where integers are read sequentially, 
// the task is to determine the median of the elements encountered so far after each new integer is read.
// There are two cases for median on the basis of data set size.
// 1. If the data set has an odd number then the middle one will be consider as median.
// 2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

// Examples:

// Input:  arr[] = [5, 15, 1, 3, 2, 8]
// Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
// Explanation: 
// After reading 1st element of stream – 5 -> median = 5.0
// After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
// After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
// After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
// After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
// After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0

// Input: arr[] = [2, 2, 2, 2]
// Output: [2.0, 2.0, 2.0, 2.0]
// Explanation: 
// After reading 1st element of stream – 2 -> median = 2.0
// After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
// After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
// After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0

// Constraints:
// 1 <= arr.size() <= 105
// 1 <= x <= 106

// SOLUTION: 

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> result;
        
        for(int num: arr){
            if(maxHeap.empty() || num<= maxHeap.top()){
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }
            
            // to balance the heaps
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // to Compte median
            if(maxHeap.size() == minHeap.size()){
                result.push_back((maxHeap.top() +  minHeap.top())/2.0);
            }else{
                result.push_back(maxHeap.top());
            }
        }
        return result;
    }
};
