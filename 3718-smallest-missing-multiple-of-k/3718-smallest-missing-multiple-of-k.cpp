class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s;

        for(int x : nums) {
            s.insert(x);
        }

        int i = 1;

        while(true) {
            if(s.find(k * i) == s.end()) {
                return k * i;
            }
            i++;
        }
    }
};