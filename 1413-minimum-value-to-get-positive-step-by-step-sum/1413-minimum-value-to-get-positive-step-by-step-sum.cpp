class Solution {
public:
    int minStartValue(vector<int>& nums) {
         if (nums.empty()) return 1; 

        int current_sum = 0;
        int min_pref = 0;

        for (int num : nums) {
            current_sum += num;
            min_pref = min(min_pref, current_sum);
        }

        
        return 1 - min_pref;
    }
};