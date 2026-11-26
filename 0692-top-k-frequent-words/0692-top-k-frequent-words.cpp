class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string &word : words) {
            freq[word]++;
        }

        auto cmp = [&](string a, string b) {
            if (freq[a] == freq[b])
                return a < b;

            return freq[a] > freq[b];
        };

        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for (auto &it : freq) {
            pq.push(it.first);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};