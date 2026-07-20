class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;
        int totalOnes = 0;
        int n = s.size();

        for (char ch : s)
            if (ch == '1')
                totalOnes++;

        for (int p = 0; p < strs.size(); p++) {
            string target = strs[p];

            int fixedOnes = 0, remainingQuestions = 0;

            for (char ch : target) {
                if (ch == '1')
                    fixedOnes++;
                if (ch == '?')
                    remainingQuestions++;
            }

            int needOnes = totalOnes - fixedOnes;

            if (needOnes < 0 || needOnes > remainingQuestions) {
                ans.push_back(false);
                continue;
            }

           
            for (int i = n - 1; i >= 0; i--) {
                if (target[i] == '?') {
                    if (needOnes > 0) {
                        target[i] = '1';
                        needOnes--;
                    } else {
                        target[i] = '0';
                    }
                    remainingQuestions--;
                }
            }

            int i = 0, j = 0;
            bool ok = true;

            while (true) {
                while (i < n && s[i] != '1')
                    i++;
                while (j < n && target[j] != '1')
                    j++;

                if (i == n && j == n)
                    break;

                if (i == n || j == n) {
                    ok = false;
                    break;
                }

                if (j < i) {
                    ok = false;
                    break;
                }

                i++;
                j++;
            }

            ans.push_back(ok);
        }

        return ans;
    }
};