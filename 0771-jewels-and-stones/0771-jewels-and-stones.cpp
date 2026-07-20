class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s;
        unordered_map<char, int> mps;

        for (int i = 0; i < jewels.size(); i++) {
            s.insert(jewels[i]);
        }

        for (int i = 0; i < stones.size(); i++) {
            mps[stones[i]]++;
        }

        int ans = 0;
        for (char it : s) {
            if (mps.contains(it)) {
                ans += mps[it];
            }
        }
        return ans;
    }
};