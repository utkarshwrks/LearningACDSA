#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b) {
    if (a == b) return 0;
    else if (a > b) return 1;
    else return -1;
}

int avg(int a, int b) {
    return (a + b) / 2;
}

void callMedian(int element,
                priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini,
                int &median) {

    switch (signum(maxi.size(), mini.size())) {

        case 0: // sizes equal
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1: // maxi has more elements
            if (element > median) {
                mini.push(element);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = avg(maxi.top(), mini.top());
            break;

        case -1: // mini has more elements
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = avg(maxi.top(), mini.top());
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n) {

    vector<int> ans;

    priority_queue<int> maxheap;  // left side (max heap)
    priority_queue<int, vector<int>, greater<int>> minheap; // right side (min heap)

    int median = 0;

    for (int i = 0; i < n; i++) {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }

    return ans;
}
