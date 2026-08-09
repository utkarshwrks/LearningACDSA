class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long, int> cnt;
        cnt.reserve(planks.size() * 2);

        for (int x : planks)
            cnt[x]++;

        vector<long long> vals;
        vals.reserve(cnt.size());

        for (auto& p : cnt)
            vals.push_back(p.first);

        int n = vals.size();

        unordered_map<long long, int> res;
        res.reserve(1 << 20);

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            long long a = vals[i];

            ans = max(ans, cnt[a]);

            res[2 * a] += cnt[a] / 2;

            for (int j = i + 1; j < n; ++j) {
                long long b = vals[j];
                res[a + b] += min(cnt[a], cnt[b]);
            }
        }

        for (auto& [h, pairs] : res) {
            auto it = cnt.find(h);
            int singles = (it == cnt.end() ? 0 : it->second);

            ans = max(ans, pairs + singles);
        }

        return ans;
    }
};