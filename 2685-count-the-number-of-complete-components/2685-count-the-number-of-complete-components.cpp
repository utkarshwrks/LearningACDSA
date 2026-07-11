class Solution {
public:
    void dfs(int node, unordered_map<int, bool>& vis,
             unordered_map<int, list<int>>& adj, int &edges, int &k) {
        vis[node] = true;
        k++;

        for (int nbr : adj[node]) {
            edges++;
            if (!vis[nbr]) {
                dfs(nbr, vis, adj, edges, k);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        int count = 0;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> vis;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                int e = 0;
                int k = 0;
                dfs(i, vis, adj, e, k);
                e/=2;
                if (e == (k * (k - 1)) / 2)
                    count++;
            }
        }
        return count;
    }
};