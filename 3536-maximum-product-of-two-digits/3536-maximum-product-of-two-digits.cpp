class Solution {
public:
    int maxProduct(int n) {
        string demo=to_string(n);
        sort(demo.begin(),demo.end());
        int end=demo.size()-1;
        int maxi=(demo[end]-'0')*(demo[end-1]-'0');
        return maxi;
    }
};