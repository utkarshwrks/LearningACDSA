class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<long long> cur(m + 1, 0);
        cur[m - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                } else if (j + 1 < m) {
                    cur[j] += cur[j + 1];
                }
            }
        }
        return cur[0];
    }
};