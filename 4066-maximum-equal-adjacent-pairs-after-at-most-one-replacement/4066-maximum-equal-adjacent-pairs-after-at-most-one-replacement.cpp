class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int base = 0;

        map<pair<int,int>, int> freq;

        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] == nums[i + 1]) {
                base++;
            }
            else {
                int x = min(nums[i], nums[i + 1]);
                int y = max(nums[i], nums[i + 1]);

                freq[{x, y}]++;
            }
        }

        int best = 0;

        for (auto &[p, cnt] : freq) {
            best = max(best, cnt);
        }

        return base + best;
    }
};