class Solution {
public:
    int solvememo(int idx, int endIdx, vector<int>& slices, int n,
                  vector<vector<int>>& dp) {
        if (n == 0 || idx > endIdx) {
            return 0;
        }
        if (dp[idx][n] != -1) {
            return dp[idx][n];
        }

        int take = slices[idx] + solve(idx + 2, endIdx, slices, n - 1);
        int nottake = 0 + solve(idx + 1, endIdx, slices, n);

        dp[idx][n] = max(take, nottake);
        return dp[idx][n];
    }
    int solvetab(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));

        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

        for (int idx = k - 2; idx >= 0; idx--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[idx] + dp1[idx + 2][n - 1];
                int nottake = 0 + dp1[idx + 1][n];

                dp1[idx][n] = max(take, nottake);
            }
        }
        int case1=dp1[0][k/3];



        for (int idx = k - 1; idx >= 1; idx--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[idx] + dp2[idx + 2][n - 1];
                int nottake = 0 + dp2[idx + 1][n];

                dp2[idx][n] = max(take, nottake);
            }
        }
        int case2=dp2[1][k/3];


        return max(case1, case2);
    }
    int solve(int idx, int endIdx, vector<int>& slices, int n) {
        if (n == 0 || idx > endIdx) {
            return 0;
        }

        int take = slices[idx] + solve(idx + 2, endIdx, slices, n - 1);
        int nottake = 0 + solve(idx + 1, endIdx, slices, n);

        return max(take, nottake);
    }
    int solvese(vector<int>& slices) {
        int k = slices.size();

        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);

        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);

        for (int idx = k - 2; idx >= 0; idx--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[idx] +next1[n - 1];
                int nottake = 0 +curr1[n];

               prev1[n] = max(take, nottake);
            }
            next1=curr1;
            curr1=prev1;
        }
        int case1=curr1[k/3];



        for (int idx = k - 1; idx >= 1; idx--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[idx] +next2[n - 1];
                int nottake = 0 + curr2[n];

                prev2[n] = max(take, nottake);
            }
            next2=curr2;
            curr2=prev2;
        }
        int case2=curr2[k/3];


        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();

        // vector<vector<int>> dp1(k, vector<int>(k, -1));

        // int case1 = solvememo(0, k - 2, slices, k / 3, dp1);

        // vector<vector<int>> dp2(k, vector<int>(k, -1));

        // int case2 = solvememo(1, k - 1, slices, k / 3, dp2);

        // return max(case1, case2);


        // return solvetab(slices);

         return solvese(slices);
    }
};