class Solution {
public:
    void getAns(int n,string &s,int open,int close, vector<string> &ans){
        if(s.length()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            getAns(n,s,open+1,close,ans);
            s.pop_back();
        }
        if(close<open){
             s.push_back(')');
            getAns(n,s,open,close+1,ans);
            s.pop_back();
            

        }




    }
    vector<string> generateParenthesis(int n) {
        string s;
        int open = 0;
int close = 0;

        vector<string> ans;

        getAns(n,s,open ,close,ans);

        return ans;
        
    }
};
