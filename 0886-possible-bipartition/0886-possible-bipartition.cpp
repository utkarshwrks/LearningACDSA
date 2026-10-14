class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        queue<int> q;
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1)
                continue;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neigh : adj[node]) {
                    if (color[neigh] == -1) {
                        color[neigh] = !color[node];
                        q.push(neigh);
                    }  else if (color[neigh] == color[node]) {
                        return false;
                    }
                }
            }

        }
         return true;
    }
};