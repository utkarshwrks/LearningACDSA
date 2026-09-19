class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int bad = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                if (bad != -1)
                    return false;
                bad = i;
            }
        }

        if (bad == -1)
            return true;

        bool removeCurrent = (bad == 1 || nums[bad] > nums[bad - 2]);
        bool removePrevious = (bad == n - 1 || nums[bad + 1] > nums[bad - 1]);

        return removeCurrent || removePrevious;
    }
};