class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> work;
        k%=m*n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                work.push_back(grid[i][j]);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        int demo = n * m - k;
        if (demo == n * m)
            demo = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                    ans[i][j] = work[demo];
                    demo++;
                     if(demo==m*n) demo=0;
            }
        }
        return ans;
    }
};