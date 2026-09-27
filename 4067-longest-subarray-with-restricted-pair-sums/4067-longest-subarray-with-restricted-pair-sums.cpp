class Solution {
public:
    bool check(int x, vector<int>& freq) {

       
        for (int a = 1; a < x; a++) {
            int b = x - a;

            if (freq[a] && freq[b]) {
                if (a != b || freq[a] >= 2)
                    return false;
            }
        }

       
        for (int a = 1; x + a <= 500; a++) {
            int b = x + a;

            if (freq[a] && freq[b])
                return false;
        }

        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(501, 0);

        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {

            while (!check(nums[r], freq)) {
                freq[nums[l]]--;
                l++;
            }

            freq[nums[r]]++;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};