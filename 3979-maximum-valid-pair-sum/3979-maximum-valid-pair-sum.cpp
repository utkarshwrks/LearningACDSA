class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int best=nums[0];
        int ans=0;
        for(int i=k;i<n;i++){
            best=max(best,nums[i-k]);
            ans=max(ans,best+nums[i]);
        }
        return ans;
    }
};