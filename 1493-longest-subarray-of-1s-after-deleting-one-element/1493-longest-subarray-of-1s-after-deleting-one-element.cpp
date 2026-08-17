class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int previdx = -1;
        int startidx = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
                if (cnt > 1) {

                    startidx = previdx + 1;
                    cnt--;
                }
                previdx = i;
            }

            ans = max(ans, i - startidx);
        }

        return ans;
    }
};