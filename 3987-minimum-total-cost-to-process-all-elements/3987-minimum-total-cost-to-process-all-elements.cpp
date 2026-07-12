class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
       long long res=k;
        long long cost=0;
        for(int i=0;i<n;i++){
            
              if(nums[i]>res){
                  long long cnt=(nums[i]-res+k-1)/k;
                    res+=cnt*k;
                    cost+=cnt;
                }
                res-=nums[i];
           
        }
        __int128 ans=(__int128)cost*(cost+1)/2;
        return ans % 1000000007;
    }
};