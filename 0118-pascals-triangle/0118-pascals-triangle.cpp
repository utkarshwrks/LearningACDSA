class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (j == 0 || j == i) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = solve(i - 1, j - 1, dp) + solve(i - 1, j, dp);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;

        for (int i = 0; i < numRows; i++) {

            vector<int> curr(i + 1);
            curr[0] = 1;
            curr[i] = 1;

            for (int j = 1; j < i; j++) {
                curr[j] = prev[j - 1] + prev[j];
            }

            ans.push_back(curr);
            prev = curr;
        }
        return ans;
    }
};