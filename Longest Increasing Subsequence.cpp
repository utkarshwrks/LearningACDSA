class Solution {
  public:
    int solve(vector<int>& arr,int n,int cur,int prev){
        if(cur==n){
            return 0;
            
        }
        
        int take=0;
        if(prev == -1 || arr[prev]<arr[cur]){
            take=1+solve(arr,n,cur+1,cur);
        }
        
        int nottake=solve(arr,n,cur+1,prev);
        
        return max(take,nottake);
    }
    
     int solvememo(vector<int>& arr,int n,int cur,int prev, vector<vector<int>>& dp){
        if(cur==n){
            return 0;
            
        }
        if( dp[cur][prev+1]!=-1){
            return dp[cur][prev];
        }
        
        int take=0;
        if(prev == -1 || arr[prev]<arr[cur]){
            take=1+solve(arr,n,cur+1,cur);
        }
        
        int nottake=solve(arr,n,cur+1,prev);
        
        dp[cur][prev+1]= max(take,nottake);
        return  dp[cur][prev+1];
    }
    int solvetab(vector<int>& arr){
        int n = arr.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int cur = n-1; cur >= 0; cur--){
            for(int prev = cur-1; prev >= -1; prev--){

                int take = 0;

                if(prev == -1 || arr[prev] < arr[cur]){
                    take = 1 + dp[cur+1][cur+1];
                }

                int nottake = dp[cur+1][prev+1];

                dp[cur][prev+1] = max(take, nottake);
            }
        }

        return dp[0][0];
    }
    
    
    int solvese(vector<int>& arr){
        int n = arr.size();

       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
        for(int cur = n-1; cur >= 0; cur--){
            for(int prev = cur-1; prev >= -1; prev--){

                int take = 0;

                if(prev == -1 || arr[prev] < arr[cur]){
                    take = 1 + next[cur+1];
                }

                int nottake =next[prev+1];

                curr[prev+1] = max(take, nottake);
            }
            next=curr;
        }

        return next[0];
    }
    
    int solveop(vector<int>& arr){
        int n = arr.size();
        
        if(n==0) return 0;
        
        vector<int> ans;
        
        ans.push_back(arr[0]);
        
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }else{
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index]=arr[i];
            }
        }
        
        return ans.size();
        
        

    }

    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solvememo(arr,n,0,-1,dp);
        return solveop(arr);
    }
};