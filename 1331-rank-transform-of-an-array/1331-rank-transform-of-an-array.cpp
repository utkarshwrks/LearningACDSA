class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> demo=arr;
        sort(demo.begin(),demo.end());
        unordered_map<int,int> mp;
       
        int rank = 1;

        for(int i = 0; i < demo.size(); i++) {
            if(mp.find(demo[i]) == mp.end()) {
                mp[demo[i]] = rank;
                rank++;
            }
        }

       vector<int> ans;

       for(int i=0;i<arr.size();i++){
        ans.push_back(mp[arr[i]]);
       }

       return ans;

    }
};