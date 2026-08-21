class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, vector<vector<bool>>& vis,
             bool& subi) {

        int n = grid1.size();
        int m = grid1[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid2[i][j] == 0) {
            return;
        }

        vis[i][j] = true;

        if (grid1[i][j] == 0) {
            subi = false;
        }

        dfs(i + 1, j, grid1, grid2, vis, subi);
        dfs(i, j - 1, grid1, grid2, vis, subi);
        dfs(i - 1, j, grid1, grid2, vis, subi);
        dfs(i, j + 1, grid1, grid2, vis, subi);
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ( grid2[i][j] && !vis[i][j]) {
                    bool subi = true;
                    dfs(i, j, grid1, grid2, vis, subi);
                    if (subi)
                        ans++;
                }
            }
        }
        return ans;
    }
};