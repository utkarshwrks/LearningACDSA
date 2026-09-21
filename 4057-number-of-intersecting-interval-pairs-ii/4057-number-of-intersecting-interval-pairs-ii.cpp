class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> start, end;

        for (auto &x : intervals) {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        long long ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < i && end[j] < start[i])
                j++;

            ans += i - j;
        }

        return ans;
    }
};