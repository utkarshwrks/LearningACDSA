class Solution {
public:
    
    int solveso(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> next(m), curr(m);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    curr[j] = grid[i][j];
                } else if (i == n - 1) {
                    curr[j] = grid[i][j] + curr[j + 1];
                } else if (j == m - 1) {
                    curr[j] = grid[i][j] + next[j];
                } else {
                    curr[j] = grid[i][j] + min(next[j], curr[j + 1]);
                }
            }

            next = curr;
        }
        return next[0];
    }
   

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
     return solveso(grid);
        
    }
};