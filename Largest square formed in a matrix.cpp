class Solution {
public:

    int solve(vector<vector<int>>& mat, int i, int j, int &maxi){

        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }

        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);

        if(mat[i][j] == 1){

            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);

            return ans;
        }

        return 0;
    }
    
    int solvememo(vector<vector<int>>& mat, int i, int j, int &maxi, vector<vector<int>> &dp){

        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solvememo(mat, i, j+1, maxi, dp);
        int diagonal = solvememo(mat, i+1, j+1, maxi, dp);
        int down = solvememo(mat, i+1, j, maxi, dp);

        if(mat[i][j] == 1){

            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);

            return dp[i][j];
        }

        dp[i][j] = 0;
        return 0;
    }
    
   
    int solvetab(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int maxi = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(mat[i][j] == 1){

                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);

                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxi;
    }
    
 int solvese(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();

        vector<int> cur(m+1,0);
        vector<int> next(m+1,0);

        int maxi = 0;

        for(int i = n-1; i >= 0; i--){

            for(int j = m-1; j >= 0; j--){

                int right = cur[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(mat[i][j] == 1){

                    cur[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, cur[j]);

                } else {
                    cur[j] = 0;
                }
            }

            next = cur;
        }

        return maxi;
    }


    int maxSquare(vector<vector<int>>& mat) {

        // int maxi = 0;

        // int n = mat.size();
        // int m = mat[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // solvememo(mat, 0, 0, maxi, dp);

        // return solvetab(mat);
        return solvese(mat);
    }
};