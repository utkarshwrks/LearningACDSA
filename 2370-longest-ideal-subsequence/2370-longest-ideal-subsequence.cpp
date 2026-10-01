class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        for (char ch : s) {
            int x = ch - 'a';

            int best = 0;

            for (int c = 0; c < 26; c++) {
                if (abs(x - c) <= k) {
                    best = max(best, dp[c]);
                }
            }

            dp[x] = best + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};