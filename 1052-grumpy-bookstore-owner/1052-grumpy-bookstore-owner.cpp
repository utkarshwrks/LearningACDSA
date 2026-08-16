class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int ans = 0;
        int n = grumpy.size();
        vector<int> pref(n, 0);

        pref[0] = (grumpy[0] ? customers[0] : 0);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (grumpy[i] ? customers[i] : 0);
        }

        for (int i = 0; i < n; i++) {

            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        int demo = pref[k-1];

        for (int i = 1; i + k-1 < n; i++) {

            demo = max(demo, pref[i + k-1] - pref[i - 1]);
        }
        ans += demo;
        return ans;
    }
};