class Solution {
public:
    bool solvememo(int i,int j,string s,string p,  vector<vector<int>> &dp){
          int n = s.size();
        int m = p.size();

        if (j == m)
            return i == n;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < m && p[j + 1] == '*') {
            return dp[i][j] =
                solvememo(i, j + 2, s, p, dp) ||
                (match && solvememo(i + 1, j, s, p, dp));
        }

        return dp[i][j] =
            match && solvememo(i + 1, j + 1, s, p, dp);
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solvememo(0,0,s,p,dp);
    }
};