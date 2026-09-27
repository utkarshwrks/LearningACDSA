class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> se;
        string ans;
        int n=s.size();
         string now="";
        for(int i=0;i<n;i++){
           
            if(s[i]=='(' ){
               se.push(now);
               now.clear();
            }else if(s[i]==')'){
                reverse(now.begin(), now.end());

                string demo = se.top();
                se.pop();

                now = demo + now;
            }
            else{
                now.push_back(s[i]);
            }

        }
        return now;
    }
};