class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < parent.size(); i++) {
            adj[parent[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        vector<int> depth(n);
        depth[0] = 1;

        int height = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            height = max(height, depth[u]);

            for (int v : adj[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
         long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (height - depth[i] + 1);
        }

        return ans;
    }
};