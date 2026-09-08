class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0]=1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int row = cur.first.first;
            int col = cur.first.second;
            grid[row][col]=1;
            int dist = cur.second;
            if(row==n-1 && col==n-1){
                return dist;
            }
            for (int i = 0; i < 8; i++) {
                int newr = row + dir[i].first;
                int newc = col + dir[i].second;
                if (newr >= 0 && newc >= 0 && newr < n && newc < n) {
                    if (grid[newr][newc] == 0) {
                         grid[newr][newc] = 1;
                        q.push({{newr, newc}, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};