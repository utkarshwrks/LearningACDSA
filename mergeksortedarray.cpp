#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    
    // min heap
    // {value, {arrayIndex, elementIndex}}
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    vector<int> result;

    // Step 1: push first element of each array
    for(int i = 0; i < k; i++) {
        if(!kArrays[i].empty()) {
            pq.push({kArrays[i][0], {i, 0}});
        }
    }

    // Step 2: process heap
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int value = top.first;
        int arrIndex = top.second.first;
        int eleIndex = top.second.second;

        result.push_back(value);

        // push next element from same array
        if(eleIndex + 1 < kArrays[arrIndex].size()) {
            pq.push({kArrays[arrIndex][eleIndex + 1], {arrIndex, eleIndex + 1}});
        }
    }

    return result;
}
