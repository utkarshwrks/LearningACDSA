class Solution {
public:
    int solve(vector<int>& satisfaction, int idx, int time) {
        if (idx == satisfaction.size()) {
            return 0;
        }
        int include = satisfaction[idx] * (time + 1) +
                      solve(satisfaction, idx + 1, time + 1);
        int exclude = solve(satisfaction, idx + 1, time);
        return max(include, exclude);
    }
    int solvememo(vector<int>& satisfaction, int idx, int time,
                  vector<vector<int>>& dp) {
        if (idx == satisfaction.size()) {
            return 0;
        }
        if (dp[idx][time] != -1) {
            return dp[idx][time];
        }
        int include = satisfaction[idx] * (time + 1) +
                      solvememo(satisfaction, idx + 1, time + 1, dp);
        int exclude = solvememo(satisfaction, idx + 1, time, dp);
        dp[idx][time] = max(include, exclude);
        return dp[idx][time];
    }

    int solvetab(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = n - 1; time >= 0; time--) {
                int include =
                    satisfaction[idx] * (time + 1) + dp[idx + 1][time + 1];
                int exclude = dp[idx + 1][time];
                dp[idx][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }


     int solvese(vector<int>& satisfaction) {
        int n = satisfaction.size();
       vector<int> cur(n+1,0);
        vector<int> next(n+1,0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = n - 1; time >= 0; time--) {
                int include =
                    satisfaction[idx] * (time + 1) + next[time + 1];
                int exclude = next[time];
               cur[time] = max(include, exclude);
            }
            next=cur;
        }
        return next[0];
    }
    int  solveop(vector<int>& satisfaction){
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            int count =1;
            for(int j=i;j<n;j++){
                sum+=satisfaction[j]*count;
                count++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solvememo(satisfaction, 0, 0, dp);
        return solveop(satisfaction);
    }
};