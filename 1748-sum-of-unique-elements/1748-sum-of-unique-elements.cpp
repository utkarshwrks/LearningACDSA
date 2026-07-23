class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x: nums){
            m[x]++;
        }
        int ans=0;
        for(auto &it: m){
            if(it.second<=1){
                ans+=it.first;
            }
        }
        return ans;
    }
};