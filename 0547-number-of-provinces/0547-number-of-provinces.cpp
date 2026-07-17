class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis,
             int ans) {
        if (vis[node])
            return;

        vis[node]=true;

        for (int neighbor : adj[node]) {
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis,ans);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
};