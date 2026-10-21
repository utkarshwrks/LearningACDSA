class Solution {
public:
    bool solvememo(int i,int sum,int target,vector<vector<int>> &dp,vector<int> &nums){
        int n=nums.size();
        if(sum==target){
            return true;
        }
          if (i == n || sum > target) {
            return false;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
       
        bool inclu=solvememo(i+1,sum+nums[i],target,dp,nums);
        bool excl=solvememo(i+1,sum,target,dp,nums);
        return dp[i][sum]=(inclu || excl);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int x: nums){
            totalsum+=x;
        }
        sort(nums.begin(),nums.end());
        if(totalsum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int>(totalsum/2+1,-1));
        return solvememo(0,0,totalsum/2,dp,nums);
    }
};