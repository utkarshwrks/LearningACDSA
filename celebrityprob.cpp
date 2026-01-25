#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getCelebrity(vector<vector<int>>& arr) {
    int n = arr.size();
    stack<int> s;

    // Step 1: push all people
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: eliminate non-celebrities
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();

        if (arr[i][j] == 0) {
            // i does NOT know j ? j can't be celebrity
            s.push(i);
        } else {
            // i knows j ? i can't be celebrity
            s.push(j);
        }
    }

    // Step 3: possible celebrity
    int celeb = s.top();

    // Step 4: verify celebrity
    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            // celeb should know nobody
            // everybody should know celeb
            if (arr[celeb][i] == 1 || arr[i][celeb] == 0) {
                return -1;
            }
        }
    }

    return celeb;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int ans = getCelebrity(arr);
    cout << ans;
}
