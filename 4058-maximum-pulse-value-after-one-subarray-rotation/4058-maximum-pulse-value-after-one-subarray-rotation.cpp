class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long original = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                original += nums[i];
            else
                original -= nums[i];
        }

        if (n < 2)
            return original;

        const long long INF = 4e18;

        long long odd = INF;
        long long even = INF;
        long long minEven = 0;

        for (int i = 0; i < n; i++) {
            long long x = (i % 2 == 0 ? nums[i] : -1LL * nums[i]);

            long long newOdd = min(x, even + x);
            long long newEven = odd + x;

            odd = newOdd;
            even = newEven;

            minEven = min(minEven, even);
        }

        return original - 2LL * minEven;
    }
};