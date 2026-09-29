class Solution {
public:
    bool solvememo(vector<vector<char>>& grid, int i, int j, int balance, int n,
                   int m, vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m)
            return false;

        if (balance < 0)
            return false;

        if (balance > (n - i) + (m - j) - 1)
            return false;
        if ((i == n - 1 && j == m - 1) && balance == 0) {
            return true;
        }

        if (grid[i][j] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];
        bool right = solvememo(grid, i, j + 1, balance, n, m, dp);
        bool down = solvememo(grid, i + 1, j, balance, n, m, dp);
        return dp[i][j][balance] = (right || down);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if ((n + m - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));

        return solvememo(grid, 0, 0, 0, n, m, dp);
    }
};