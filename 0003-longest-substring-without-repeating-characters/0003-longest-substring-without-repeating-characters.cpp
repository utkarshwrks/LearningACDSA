class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<char> st;
        int ans = INT_MIN;
        int demo = 0;
        int left=0;

        for (int i = 0; i < s.size(); i++) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[left]);
                left++;
                demo--;
            }

            st.insert(s[i]);
            demo++;

            ans = max(demo, ans);
        }
        return ans;
    }
};