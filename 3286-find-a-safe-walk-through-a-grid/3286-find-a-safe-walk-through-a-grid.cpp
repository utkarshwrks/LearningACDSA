class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> besthlt(n, vector<int>(m, -1));

        if (grid[0][0] == 1) {
            health--;
        }

        if (health <= 0) {
            return false;
        }
        pq.push({health, {0, 0}});
        besthlt[0][0] = health;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty() ) {

            int curhlt = pq.top().first;
            int currow = pq.top().second.first;
            int curcol = pq.top().second.second;

            pq.pop();

            if (currow == n - 1 && curcol == m - 1)
                return true;

            if(curhlt<besthlt[currow][curcol]) continue;

            for (int i = 0; i < 4; i++) {
                int nrow = currow + dr[i];
                int ncol = curcol + dc[i];

                if (nrow < 0 || ncol < 0 || nrow > n - 1 || ncol > m - 1)
                    continue;

                int newhlt = curhlt;
                if (grid[nrow][ncol] == 1)
                    newhlt--;

                if (newhlt <= 0)
                    continue;

                if (newhlt > besthlt[nrow][ncol]) {
                    besthlt[nrow][ncol] = newhlt;
                    pq.push({newhlt, {nrow, ncol}});
                }
            }
        }
        return false;
    }
};