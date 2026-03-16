// User function template for C++

class Solution {
  public:
    int solve(int idx,int diff,vector<int>& arr){
        if(idx<0) return 0;
        
        
        int ans=0;
        for(int j=idx-1;j>=0;j--){
             if(arr[idx]-arr[j]==diff){
                 ans= max(ans,1+solve(j,diff,arr));
             }
        }
        return ans;
    }
    
   int solvememo(int idx,int diff,vector<int>& arr, unordered_map<int,int> dp[]){
        if(idx < 0) return 0;

        if(dp[idx].count(diff)){
            return dp[idx][diff];
        }

        int ans = 0;

        for(int j = idx-1; j >= 0; j--){
            if(arr[idx] - arr[j] == diff){
                ans = max(ans , 1 + solvememo(j , diff , arr , dp));
            }
        }

        dp[idx][diff] = ans;
        return ans;
    }

    int lengthOfLongestAP(vector<int>& arr) {

    int n = arr.size();
    if(n <= 2) return n;

    int ans = 2;

    unordered_map<int,int> dp[n];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){

            int diff = arr[i] - arr[j];
            int cnt = 1;

            if(dp[j].count(diff)){
                cnt = dp[j][diff];
            }

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}
};