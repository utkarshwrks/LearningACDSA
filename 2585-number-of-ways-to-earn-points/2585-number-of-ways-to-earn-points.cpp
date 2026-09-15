class Solution {
public:
      int MOD = 1e9 + 7;
    int solvememo(vector<vector<int>>& dp, int target, int i,
                  vector<vector<int>>& types) {
        int n = types.size();

        if (target == 0) {
            return 1;
        }
        if (target < 0 || i == n) {
            return 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        long long ans = 0;

        int count = types[i][0];
        int points = types[i][1];
        for (int j = 0; j <= count; j++) {
            int rem = target - j * points;
            if (rem < 0)
                break;

            ans += solvememo(dp, rem, i + 1, types);
            ans %= MOD;
        }
        return dp[i][target] = ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solvememo(dp, target, 0, types);
    }
};