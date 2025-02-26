// PROBLEM: Get Min from Stack

// Given q queries, You task is to implement the following four functions for a stack:

// push(x) – Insert an integer x onto the stack.
// pop() – Remove the top element from the stack.
// peek() - Return the top element from the stack. If the stack is empty, return -1.
// getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
// Each query can be one of the following:
// 1 x : Push x onto the stack.
// 2 : Pop the top element from the stack.
// 3: Return the top element from the stack. If the stack is empty, return -1.
// 4: Return the minimum element from the stack.

// Examples:

// Input: q = 7, queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
// Output: [3, 2, 1]
// Explanation: 
// push(2): Stack is [2]
// push(3): Stack is [2, 3]
// peek(): Top element is 3
// pop(): Removes 3, stack is [2]
// getMin(): Minimum element is 2
// push(1): Stack is [2, 1]
// getMin(): Minimum element is 1

// Input: q = 4, queries = [[1, 4], [1, 2], [4], [3]]
// Output: [2, 2]
// Explanation: 
// push(4): Stack is [4]
// push(2): Stack is [4, 2]
// getMin(): Minimum element is 2
// peek(): Top element is 2

// Input: q = 5, queries = [[1, 10], [4], [1, 5], [4], [2]]
// Output: [10, 5]
// Explanation: 
// push(10): Stack is [10]
// getMin(): Minimum element is 10
// push(5): Stack is [10, 5]
// getMin(): Minimum element is 5
// pop(): Removes 5, stack is [10]

// Constraints:
// 1 <= q <= 105
// 0 <= values on the stack <= 109

// SOLUTION: 

class Solution {
  private:
    stack<int> mainStack;
    stack<int> minStack;
  
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        mainStack.push(x);
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!mainStack.empty()){
            if(mainStack.top() == minStack.top()){
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return mainStack.empty() ? -1 : mainStack.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return minStack.empty() ? -1 : minStack.top();
    }
};
