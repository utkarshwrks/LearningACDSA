class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2 != 0)
            return 0;

        int required = (total + target) / 2;

        vector<vector<int>> dp(
            nums.size() + 1,
            vector<int>(required + 1, 0)
        );

        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= required; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i - 1] <= j)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[nums.size()][required];
    }
};