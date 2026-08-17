class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= n || j >= m || i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

       int ans = 0;

       
        if (i - 1 >= 0 &&
            j + 1 < m &&
            grid[i - 1][j + 1] > grid[i][j]) {

            ans = max(ans, 1 + solve(i - 1, j + 1, dp, grid));
        }

       
        if (j + 1 < m &&
            grid[i][j + 1] > grid[i][j]) {

            ans = max(ans, 1 + solve(i, j + 1, dp, grid));
        }

        if (i + 1 < n &&
            j + 1 < m &&
            grid[i + 1][j + 1] > grid[i][j]) {

            ans = max(ans, 1 + solve(i + 1, j + 1, dp, grid));
        }

        return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, dp, grid));
        }
        return ans;
    }
};