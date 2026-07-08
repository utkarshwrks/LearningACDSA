class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

       
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] - '0');
        }

       
        vector<int> pos;
        vector<int> dig;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int m = dig.size();

       
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

      
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + dig[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = pref[r + 1] - pref[l];

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            if (itL == itR) {
                ans.push_back(0);
                continue;
            }

            int L = itL - pos.begin();
            int R = (itR - pos.begin()) - 1;

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 (prefNum[L] * pow10[len]) % MOD +
                 MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};