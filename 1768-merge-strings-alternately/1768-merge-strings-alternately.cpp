class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0;
        int j=0;
        string ans;
        while(i<n && j<m){
          ans.push_back(word1[i++]);
          ans.push_back(word2[j++]);
        }
        if(i<n){
          ans += word1.substr(i);
        }
        if(j<m){
           ans += word2.substr(j);
        }
        return ans;
    }
};