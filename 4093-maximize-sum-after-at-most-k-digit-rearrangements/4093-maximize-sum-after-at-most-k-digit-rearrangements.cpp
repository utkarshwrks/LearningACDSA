class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long ans=0;
         vector<int> gains;
        
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            sort(s.begin(), s.end(), greater<char>());

            int demo = stoi(s);
            ans += nums[i];
            gains.push_back(demo - nums[i]);
        }

        sort(gains.begin(), gains.end(), greater<int>());

        for (int i = 0; i < k; i++) {
            ans += gains[i];
        }

        return ans;
    }
};