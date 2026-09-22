class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == 0)
            return target == 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = solve(i - 1, target, nums, dp);

        int take = 0;
        if (nums[i - 1] <= target)
            take = solve(i - 1, target - nums[i - 1], nums, dp);

        return dp[i][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2 != 0)
            return 0;

        int required = (total + target) / 2;

        vector<vector<int>> dp(
            nums.size() + 1,
            vector<int>(required + 1, -1)
        );

        return solve(nums.size(), required, nums, dp);
    }
};