class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;

        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }

          vector<int> ans1, ans2;
        for (int x : s1) {
            if (!s2.count(x))
                ans1.push_back(x);
        }

        for (int x : s2) {
            if (!s1.count(x))
                ans2.push_back(x);
        }

      
        return {ans1,ans2};

    }
};