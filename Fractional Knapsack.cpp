#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // pair: {value/weight ratio, index}
        vector<pair<double, int>> v;
        
        for (int i = 0; i < n; i++) {
            double ratio = (1.0 * val[i]) / wt[i];
            v.push_back({ratio, i});
        }
        
        // sort in descending order of ratio
        sort(v.begin(), v.end(), greater<pair<double, int>>());
        
        double totalValue = 0.0;
        
        for (int i = 0; i < n; i++) {
            int idx = v[i].second;
            
            if (wt[idx] <= capacity) {
                // take full item
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                // take fractional part
                totalValue += v[i].first * capacity;
                break;
            }
        }
        
        return totalValue;
    }
};