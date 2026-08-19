class Solution {
public:
    string dfs(string u, unordered_map<string, string>& adj) {
        if (!adj.count(u))
            return u;

        return dfs(adj[u], adj);
    }

    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> adj;
        unordered_set<string> dest;

        for (int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]] = paths[i][1];
            dest.insert(paths[i][1]);
        }

        string start;

        for (int i = 0; i < paths.size(); i++) {
            if (!dest.count(paths[i][0])) {
                start = paths[i][0];
                break;
            }
        }

        return dfs(start, adj);
    }
};