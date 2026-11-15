class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int AND = nums[i];
            int mn = nums[i];

            for (int j = i; j < n; j++) {
                AND &= nums[j];
                mn = min(mn, nums[j]);

                if (AND == mn) {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};