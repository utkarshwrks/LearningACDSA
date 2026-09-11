class Solution {
public:
    int ans = 0;
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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(amount, coins, dp, n, 0);
    }
};