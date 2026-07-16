class Solution {
public:
   
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixGCD(n);
        long long maxi=nums[0];

        for(int i=0;i<n;i++){
            
           maxi = max(maxi, (long long)nums[i]);
            prefixGCD[i] = gcd((long long)nums[i], maxi);
           
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        long long sum=0;
        int j=n-1;
        for(int i=0;i<n/2;i++){
            sum+=gcd(prefixGCD[i],prefixGCD[j]);
            j--;
        }
        return sum;
    }
};