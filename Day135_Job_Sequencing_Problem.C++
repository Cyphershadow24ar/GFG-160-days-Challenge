// PROBLEM: Job Sequencing Problem

// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. 
// Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
// You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:
// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

// Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

// Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

// Constraints:
// 1 ≤ deadline.size() == profit.size() ≤ 105
// 1 ≤ deadline[i] ≤ deadline.size()
// 1 ≤ profit[i] ≤ 500

// SOLUTION:

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        for(int i =0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDeadline = 0;
        for(int d: deadline){
            maxDeadline = max(maxDeadline, d);
        }
        
        vector<int> parent(maxDeadline + 1);
        for(int i =0; i<= maxDeadline; i++){
            parent[i] = i;
        }
        
        function<int(int) > find = [&](int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        
        int count = 0, totalProfit = 0;
        
        for(auto& job : jobs){
            int p = job.first, d = job.second;
            int availableSlot = find(d);
            
            if(availableSlot > 0){
                totalProfit += p;
                count++;
                parent[availableSlot] = find(availableSlot - 1);
            }
        }
        return {count, totalProfit};
    }
};
