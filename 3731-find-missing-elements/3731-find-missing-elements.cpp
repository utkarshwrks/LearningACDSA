class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;

        for(int i=1;i<nums.size();i++){
           int prev =nums[i-1];
           int cur=nums[i];

           if(cur-prev>1){
            for(int j=prev+1;j<cur;j++){
                ans.push_back(j);
            }
           }
        }
        return ans;
        
    }
};