class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string ans = "123456789";
        vector<int> res;

        int st = to_string(low).size();
        int end = to_string(high).size();

        while (st <= end) {
            for (int i = 0; i + st <= ans.size(); i++) {
                string demo = ans.substr(i, st);
                int num = stoi(demo);

                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }

            st++;
        }

        sort(res.begin(), res.end());
        return res;
    }
};