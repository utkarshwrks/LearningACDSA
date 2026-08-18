class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int winsize=2*k+1;
        int end=winsize-1;
        int n=nums.size();
        vector<int> ans(n,-1);
       vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(end>=n){
                break;
            }
            int start = i;

            long long sum;

            if (start == 0) {
                sum = prefix[end];
            } else {
                sum = prefix[end] - prefix[start - 1];
            }

            ans[i + k] = sum / winsize;

            end++;
        }
        return ans;
    }
};