#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a, int b) {
    a %= MOD;
    b %= MOD;
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (int)((1LL * a * b) % MOD);
}

/* ---------- Memoization ---------- */
int solvememo(int n, int k, vector<int> &dp) {
    if (n == 1) return k;
    if (n == 2) return add(k, mul(k, k - 1));

    if (dp[n] != -1) return dp[n];

    dp[n] = add(
        mul(solvememo(n - 2, k, dp), k - 1),
        mul(solvememo(n - 1, k, dp), k - 1)
    );

    return dp[n];
}

/* ---------- Tabulation ---------- */
int solvetab(int n, int k) {
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++) {
        dp[i] = add(
            mul(dp[i - 2], k - 1),
            mul(dp[i - 1], k - 1)
        );
    }

    return dp[n];
}

int solvetabso(int n, int k) {
    vector<int> dp(n + 1, 0);

  int prev2 = k;
  int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++) {
       int ans = add(
            mul(prev2, k - 1),
            mul(prev1, k - 1)
        );

        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    return solvetabso(n, k);   // best approach
}