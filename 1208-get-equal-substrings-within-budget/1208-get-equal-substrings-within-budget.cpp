class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(s[i] - t[i]);
        }
        int sum = 0;
        int size = 0;
        int j = 0;
        int firstele = diff[j];
        int ans = 0;
        for (int i = 0; i < n; i++) {

            sum += diff[i];
            size++;
            while (sum > maxCost) {
                sum -= diff[j++];
                size--;
            }
            ans = max(size, ans);
        }
        return ans;
    }
};