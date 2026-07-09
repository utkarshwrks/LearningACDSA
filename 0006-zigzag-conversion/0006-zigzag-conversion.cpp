class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int gap = 2 * (numRows - 1);
        int n = s.size();

        string ans;

        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                int j = i;
                while (j < n) {
                    ans.push_back(s[j]);
                    j += gap;
                }
            } else {
                int j = i;
                int downgap = gap - 2 * i;
                int upgap = 2 * i;

                while (j < n) {

                    ans.push_back(s[j]);

                    j += downgap;

                    if (j >= n)
                        break;

                    ans.push_back(s[j]);

                    j += upgap;
                }
            }
        }
        return ans;
    }
};