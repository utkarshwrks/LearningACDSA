class Solution {
  public:
    string reverseWords(string &s) {
        string ans = "";
        string temp = "";
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '.') {
                if(temp != "") {   // ? skip empty words
                    reverse(temp.begin(), temp.end());
                    
                    if(!ans.empty()) ans += "."; // avoid leading dot
                    
                    ans += temp;
                    temp.clear();
                }
            } else {
                temp += s[i];
            }
        }
        
        // last word
        if(temp != "") {
            reverse(temp.begin(), temp.end());
            if(!ans.empty()) ans += ".";
            ans += temp;
        }
        
        return ans;
    }
};