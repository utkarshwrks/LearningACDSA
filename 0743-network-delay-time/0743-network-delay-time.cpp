class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        int m = times.size();

        for (int i = 0; i < m; i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto e : adj[u]) {
                int v = e.first;
                int wt = e.second;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};