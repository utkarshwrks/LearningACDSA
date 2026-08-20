class Solution {
public:
    bool island;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
             bool& island) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) {

            return;
        }
        if (grid[i][j] == 1) {
            return;
        }
        if (vis[i][j]) {
            return;
        }
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            island = false;
        vis[i][j] = true;
        dfs(grid, vis, i - 1, j, island);
        dfs(grid, vis, i + 1, j, island);
        dfs(grid, vis, i, j - 1, island);
        dfs(grid, vis, i, j + 1, island);
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    bool island = true;
                    dfs(grid, vis, i, j, island);
                    if (island) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};