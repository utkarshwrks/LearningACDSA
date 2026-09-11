class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<vector<int>>& dp, int n,
              int idx) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || idx >= n) {
            return 0;
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int x = solve(amount - coins[idx], coins, dp, n, idx);

        int y = solve(amount, coins, dp, n, idx + 1);
        return dp[idx][amount] = x + y;
    }

    int solvetab(int amount, vector<int>& coins) {
                int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, 0)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {

                long long take = 0;
                long long skip = dp[i + 1][j];

                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];
                }

                long long val = take + skip;

                dp[i][j] = (val > INT_MAX) ? INT_MAX : val;
            }
        }

        return dp[0][amount];

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return solve(amount, coins, dp, n, 0);
        return solvetab(amount, coins);
    }
};