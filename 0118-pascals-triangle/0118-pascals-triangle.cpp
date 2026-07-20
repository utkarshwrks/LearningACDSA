class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (j == 0 || j == i) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = solve(i - 1, j - 1, dp) + solve(i - 1, j, dp);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<vector<int>> dp(numRows);

        for (int i = 0; i < numRows; i++) {

            dp[i].resize(i+1);

            for (int j = 0; j <= i; j++) {
                if(j==i || j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
            }
        }
        return dp;
    }
};