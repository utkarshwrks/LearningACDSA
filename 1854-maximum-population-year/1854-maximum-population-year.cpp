class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 1950;
        int maxi = 0;

        for (int year = 1950; year <= 2050; year++) {
            int cnt = 0;

            for (auto &person : logs) {
                if (year >= person[0] && year < person[1])
                    cnt++;
            }

            if (cnt > maxi) {
                maxi = cnt;
                ans = year;
            }
        }

        return ans;
    }
};