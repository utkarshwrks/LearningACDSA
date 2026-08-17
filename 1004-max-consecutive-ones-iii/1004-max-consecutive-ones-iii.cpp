class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                cnt++;

            while (cnt > k) {
                if (nums[start] == 0)
                    cnt--;

                start++;
            }

            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};