
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int, long long> mp;
        int n = edges.size();

        for (int i = 0; i < n; i++) {
            mp[edges[i]] += i;
        }

        int ans = 0;
        long long maxi = -1;

        for (int i = 0; i < n; i++) {
            if (mp[i] > maxi) {
                maxi = mp[i];
                ans = i;
            }
        }

        return ans;
    }
};
