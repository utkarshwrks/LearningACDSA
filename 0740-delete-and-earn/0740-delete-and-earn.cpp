class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for (int x : nums) {
            mp[x]++;
            maxi = max(maxi, x);
        }
        vector<int> arr(maxi + 1, 0);
        for (auto it : mp)
            arr[it.first] = it.first * it.second;

        int prev2 = 0;
        int prev1 = arr[1];
        for (int i = 2; i <= maxi; i++) {
            int incl = prev2 + arr[i];
            int excl = prev1;
            int curr = max(incl, excl);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};