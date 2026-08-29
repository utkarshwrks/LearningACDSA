class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int high, int zero, int one, vector<int>& dp) {
        if (i > high)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long ans = 0;

        if (i >= zero)
            ans += solve(i - zero, high, zero, one, dp);

        if (i >= one)
            ans += solve(i - one, high, zero, one, dp);

        return dp[i] = ans % MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        dp[0] = 1;

        for (int i = low; i <= high; i++) {
            solve(i, high, zero, one, dp);
        }

        long long ans = 0;

        for (int i = low; i <= high; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};