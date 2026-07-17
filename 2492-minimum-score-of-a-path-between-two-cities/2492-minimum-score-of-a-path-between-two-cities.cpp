class Solution {
public:
    void dfs(int src, unordered_map<int, vector<pair<int, int>>>& adj,
             vector<bool>& vis, int &ans) {
        if (vis[src])
            return;

        vis[src] = true;
        for (auto [v, wt] : adj[src]) {
             ans = min(ans, wt);
            if (!vis[v]) {
               
                dfs(v, adj, vis, ans);
            }
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int ns = roads.size();
        for (int i = 0; i < ns; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<bool> vis(n+1, false);
        int ans = INT_MAX;
        dfs(1, adj, vis, ans);
        return ans;
    }
};