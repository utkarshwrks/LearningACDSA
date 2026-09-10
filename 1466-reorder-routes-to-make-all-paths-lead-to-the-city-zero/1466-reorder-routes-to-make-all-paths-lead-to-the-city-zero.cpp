class Solution {
public:

    int dfs(vector<vector<pair<int,int>>> &adj,
            int src,
            vector<bool> &visited) {

        visited[src] = true;

        int ans = 0;

        for(auto p : adj[src]) {

            int next = p.first;
            int cost = p.second;

            if(!visited[next]) {

                ans += cost;

                ans += dfs(adj, next, visited);
            }
        }

        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);
        vector<bool> visited(n, false);

        for(auto edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        return dfs(adj, 0, visited);
    }
};