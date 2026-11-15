class Solution {
public:
    long long solve(int i, vector<int>& nums, vector<long long>& dp) {
        int n = nums.size();

        if (i >= n)
            return 0;

        if (dp[i] != LLONG_MIN)
            return dp[i];

         long long take1 = nums[i];
        long long take2 = LLONG_MIN;

        if (i + 1 < n)
            take2 = (long long)nums[i] + nums[i + 1];

        long long sum1 = take1;
        long long sum2 = take2;

        long long ans1 = sum1 - (sum1 % 3 == 0 ? solve(i + 1, nums, dp)
                                               : -solve(i + 1, nums, dp));

        long long ans2 = LLONG_MIN;

        if (i + 1 < n) {
            ans2 = sum2 - (sum2 % 3 == 0 ? solve(i + 2, nums, dp)
                                         : -solve(i + 2, nums, dp));
        }

        return dp[i] = max(ans1, ans2);
    }
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, LLONG_MIN);

        return solve(0, nums, dp);
    }
};