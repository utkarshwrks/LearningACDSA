class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, vector<int>& dp, int n) {
        if (i >= n) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int incl = solve(i + 2, dp, n);
        int excl = solve(i + 1, dp, n);
        return dp[i] = (incl + excl) % MOD;
    }
    int solvetab(int n) {
        vector<int> dp(n + 2, 0);

        dp[n] = 1;
        dp[n + 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = (dp[i + 1] + dp[i + 2]) % MOD;
        }

        return dp[0];
    }
    int solveSpace(int n) {
        long long next1 = 1; 
        long long next2 = 1; 

        for (int i = n - 1; i >= 0; i--) {
            long long curr = (next1 + next2) % MOD;
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

    int countHousePlacements(int n) {
        int ans = 0;
        vector<int> dp(n + 1, -1);
        int i = 0;
        // ans= solve(i,dp,n);
       ans = solvetab(n);
        //ans = solveSpace(n);
        return (1LL * ans * ans) % MOD;
    }
};