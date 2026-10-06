class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
          int unmatched = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
               
                if (!st.empty()  && ((st.top() == '{' && s[i] == '}') ||
                    (st.top() == '(' && s[i] == ')') ||
                    (st.top() == '[' && s[i] == ']'))) {

                        st.pop();
                }else{
                    unmatched++;
                }
            }
        }

        return st.size()+unmatched;
    }
};