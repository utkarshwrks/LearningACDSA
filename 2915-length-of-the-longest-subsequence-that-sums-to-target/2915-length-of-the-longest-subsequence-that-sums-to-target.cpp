class Solution {
public:
    int solvememo(int i, int sum, vector<int>& nums, int target,
                  vector<vector<int>>& dp) {
        int n = nums.size();

        if (sum == target) {
            return 0;
        }
        if (sum > target || i == n) {
            return INT_MIN;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        int incl = 1 + solvememo(i + 1, sum + nums[i], nums, target, dp);

        int excl = solvememo(i + 1, sum, nums, target, dp);
        return dp[i][sum] = max(incl, excl);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solvememo(0, 0, nums, target, dp);

        return ans < 0 ? -1 : ans;
    }
};