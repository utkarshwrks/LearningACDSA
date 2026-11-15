class Solution {
public:
    long long solve(int u, vector<vector<int>>& adj, vector<int>& op,
              vector<int>& score, vector<long long>& dp) {
        if (dp[u] != LLONG_MIN)
            return dp[u];

        if (adj[u].empty())
            return dp[u] = score[u];

        long long sum = 0, mn = LLONG_MAX;

        for (int v : adj[u]) {
            long long x = solve(v, adj, op, score, dp);
            sum += x;
            mn = min(mn, x);
        }

        if (op[u] == 0)
            sum -= min(0LL, mn);
        else
            sum -= mn;

        return dp[u] = score[u] + sum;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<long long> dp(n, LLONG_MIN);

        return (int)solve(0, adj, op, score, dp);
    }
};