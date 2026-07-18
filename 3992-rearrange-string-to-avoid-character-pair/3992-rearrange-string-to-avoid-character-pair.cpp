class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string xc;
        string yc;
        string rest;

        for(int i=0;i<s.size();i++){
            if(s[i]==x){
                xc.push_back(s[i]);
            }else if(s[i]==y){
                yc.push_back(s[i]);
            }else{
                rest.push_back(s[i]);
            }
        }
        string ans=yc+rest+xc;
        return ans;
    }
};