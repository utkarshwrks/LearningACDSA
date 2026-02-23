class Solution {
public: 
    int solver(vector<int>& cost,int n,vector<int> &dp){
         if(n==0) return cost[0];
         if(n==1) return cost[1];
         if(dp[n]!=-1) return dp[n];
         dp[n]= cost[n]+min(solver(cost,n-1,dp),solver(cost,n-2,dp));
         return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solver(cost,n-1,dp),solver(cost,n-2,dp));
    }
};