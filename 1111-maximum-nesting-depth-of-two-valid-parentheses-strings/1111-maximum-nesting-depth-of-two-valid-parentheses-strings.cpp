class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int level = 0;

        for (char c : seq) {
            if (c == '(') {
                level++;
                ans.push_back(level % 2);
            } else {
                ans.push_back(level % 2);
                level--;
            }
        }

        return ans;
    }
};