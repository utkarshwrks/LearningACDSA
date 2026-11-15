class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n =arr.size();
        const int MOD=1e9 + 7;
        long long even=1;
        long long odd=0;
        long long pref=0;
        int ans=0;
        for(int i=0;i<n;i++){
            pref+=arr[i];
            if(pref%2==0){
                ans=(ans+odd)%MOD;
                even++;
            }else{
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans;
    }
};