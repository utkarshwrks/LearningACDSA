class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string demo=to_string(num);
        int i=0;
       
        int ans=0;
        while(i+k<=demo.size()){
            int n=stoi(demo.substr(i,k));
           
            if( n!=0 && num%n==0 ){
                ans++;
            }
            i++;
            
        }
        return ans;
    }
};