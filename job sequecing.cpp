#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // pair: {profit, deadline}
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // sort jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        // find maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        // ????? array (time slots)
        vector<int> slot(maxDeadline + 1, -1);
        
        int countJobs = 0;
        int totalProfit = 0;
        
        // iterate over jobs
        for (int i = 0; i < n; i++) {
            int d = jobs[i].second;
            
            // find a free slot from deadline to 1
            for (int j = d; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i; // assign job
                    countJobs++;
                    totalProfit += jobs[i].first;
                    break;
                }
            }
        }
        
        return {countJobs, totalProfit};
    }
};