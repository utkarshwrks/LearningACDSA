class Solution {
public:
    pair<int, int> solvememo(vector<int>& nums, int n, int i, int j,
                             vector<vector<pair<int, int>>> &dp) {

        if (i >= n) {
            return {0, 1};
        }

        if (dp[i][j + 1].first != -1) {
            return dp[i][j + 1];
        }

       
        pair<int, int> excl = solvememo(nums, n, i + 1, j, dp);

        
        pair<int, int> incl = {0, 0};

        if (j == -1 || nums[i] > nums[j]) {
            pair<int, int> temp =
                solvememo(nums, n, i + 1, i, dp);

            incl = {temp.first + 1, temp.second};
        }

        if (incl.first > excl.first) {
            return dp[i][j + 1] = incl;
        }

        if (excl.first > incl.first) {
            return dp[i][j + 1] = excl;
        }

        return dp[i][j + 1] =
            {excl.first, incl.second + excl.second};
    }

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<pair<int, int>>> dp(
            n, vector<pair<int, int>>(n + 1, {-1, -1})
        );

        return solvememo(nums, n, 0, -1, dp).second;
    }
};