class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string now = "";

        for(char c : s) {
            if(c == '(') {
                st.push(now);
                now = "";
            }
            else if(c == ')') {
                reverse(now.begin(), now.end());

                now = st.top() + now;
                st.pop();
            }
            else {
                now += c;
            }
        }

        return now;
    }
};