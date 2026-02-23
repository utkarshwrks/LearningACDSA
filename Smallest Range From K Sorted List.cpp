#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;



int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;

    // min heap
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > minHeap;


    for(int i=0;i<k;i++){
        int element=a[i][0];
         mini=min(mini,element);
         maxi=max(maxi,element);
        minHeap.push({element, {i, 0}});
    }
    int start=mini ,end=maxi;

    while(!minHeap.empty()){
         auto top = minHeap.top();
        minHeap.pop();

        mini=top.first;
        int row=top.second.first;
        int col=top.second.second;

        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }

        if(col+1<n){
            int nextElement=a[row][col+1];
            minHeap.push({nextElement,{row,col+1}});
             maxi = max(maxi, nextElement);
        }else{
            break;
        }
    }
    return end-start+1;
}