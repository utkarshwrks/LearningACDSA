class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> adj(n, vector<int>(m));

        int val = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                adj[i][j] = val++;
            }
        }

        vector<vector<pair<int, int>>> adjlist(n * m);

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int u = adj[i][j];

                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {

                        int v = adj[nx][ny];

                        int wt = abs(heights[i][j] - heights[nx][ny]);

                        adjlist[u].push_back({v, wt});
                    }
                }
            }
        }

        vector<int> dist(n * m, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [effort, u] = pq.top();
            pq.pop();

            if (effort > dist[u])
                continue;

            if (u == n * m - 1)
                return effort;

            for (auto [v, wt] : adjlist[u]) {

                int newEffort = max(effort, wt);

                if (newEffort < dist[v]) {

                    dist[v] = newEffort;

                    pq.push({newEffort, v});
                }
            }
        }
        return 0;
    }
};