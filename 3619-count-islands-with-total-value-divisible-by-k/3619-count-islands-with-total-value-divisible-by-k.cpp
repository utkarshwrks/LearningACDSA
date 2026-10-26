
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    long long dfs(int i, int j, vector<vector<int>>& grid,
                  vector<vector<bool>>& vis, int n, int m) {
        vis[i][j] = true;
        long long sum = grid[i][j];

        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] != 0 && !vis[nx][ny]) {
                sum += dfs(nx, ny, grid, vis, n, m);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(i, j, grid, vis, n, m);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
