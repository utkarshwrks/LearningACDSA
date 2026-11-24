class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums) {
            pq.push(x);
        }

        while (k > 0) {
            int x = pq.top();
            pq.pop();

            x++;
            k--;

            pq.push(x);
        }

        long long ans = 1;

        while (!pq.empty()) {
            ans = (ans * pq.top()) % MOD;
            pq.pop();
        }

        return ans;
    }
};