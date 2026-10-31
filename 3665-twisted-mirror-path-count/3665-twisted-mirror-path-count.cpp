class Solution {
public:
    const long long MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<long long>>> dp;

    long long solve(vector<vector<int>>& grid, int i, int j, int dir) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;

        if (grid[i][j] == 1) {
            if (dir == 0) {
                ans = solve(grid, i + 1, j, 1);
            } else {
                ans = solve(grid, i, j + 1, 0);
            }
        } else {
            ans = (solve(grid, i, j + 1, 0)
                 + solve(grid, i + 1, j, 1)) % MOD;
        }

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<long long>>(
            n, vector<long long>(2, -1)
        ));

        return (solve(grid, 0, 1, 0)
              + solve(grid, 1, 0, 1)) % MOD;
    }
};