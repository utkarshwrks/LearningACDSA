class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxLight = *max_element(lights.begin(), lights.end());
        int ans = 0;

        for (int time : arrivalTime) {
            int r = time % period;

            int wait = 0;

            if (r >= maxLight) {
                wait = period - r;
            }

            ans = max(ans, wait);
        }

        return ans;
    }
};