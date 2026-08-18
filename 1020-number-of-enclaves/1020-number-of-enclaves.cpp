class Solution {
public:
    int comp;
    bool touchbound;

    void dfs(int i, int j, int &comp, bool &touchboard, vector<vector<bool>>& vis,
             vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m) {
            touchbound = true;
            return;
        }
        if (vis[i][j] || grid[i][j]==0) {
            return;
        }
       
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            touchbound = true;
        }
        vis[i][j]=true;
        comp++;
        dfs(i+1,j, comp, touchbound, vis, grid);
        dfs(i,j+1, comp, touchbound, vis, grid);
        dfs(i,j-1, comp, touchbound, vis, grid);
        dfs(i-1,j, comp, touchbound, vis, grid);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    comp = 0;
                    touchbound = false;
                    dfs(i, j, comp, touchbound, vis, grid);
                    if (touchbound == false) {
                        ans += comp;
                    }
                }
            }
        }
        return ans;
    }
};