class Solution {
public:
    int maxProduct(int n) {
        string demo=to_string(n);
        sort(demo.begin(),demo.end());
        int maxi=0;
        for(int i=1;i<demo.size();i++){
              maxi=max(maxi,(demo[i-1]-'0')*(demo[i]-'0'));
        }
        return maxi;
    }
};