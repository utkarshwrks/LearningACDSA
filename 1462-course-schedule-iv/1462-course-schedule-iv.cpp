class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<int>& vis) {
        if (src == target)
            return true;

        vis[src] = 1;

        for (int next : adj[src]) {
            if (!vis[next] && dfs(next, target, adj, vis))
                return true;
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> ans;

        for (auto& q : queries) {
            vector<int> vis(numCourses, 0);
            ans.push_back(dfs(q[0], q[1], adj, vis));
        }

        return ans;
    }
};