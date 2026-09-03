class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();

        bool allEven = true;
        for (int x : nums1) {
            if (x % 2 != 0) {
                allEven = false;
                break;
            }
        }

        if (allEven) return true;

       int mini=*min_element(nums1.begin(),nums1.end());
        return mini%2==1;

       
    }
};