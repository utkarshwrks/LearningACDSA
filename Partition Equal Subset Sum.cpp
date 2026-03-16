class Solution {
  public:
    bool solve(int idx,vector<int>& arr,int n,int target){
        if(idx>=n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        
        if(target==0){
            return 1;
        }
        
        bool incl=solve(idx+1,arr,n,target-arr[idx]);
        bool excl=solve(idx+1,arr,n,target);
        
        return incl || excl;
    }
    bool solvememo(int idx,vector<int>& arr,int n,int target,vector<vector<int>> &dp){
        if(idx>=n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        
        if(target==0){
            return 1;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool incl=solve(idx+1,arr,n,target-arr[idx]);
        bool excl=solve(idx+1,arr,n,target);
        
        dp[idx][target]= incl || excl;
        return dp[idx][target];
    }
    
    
     bool solvetab(vector<int>& arr,int n,int target){
         vector<vector<int>> dp(n+1,vector<int>(target+1,0));
          for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        
        for(int idx=n-1;idx>=0;idx--){
            for(int t=0;t<=target;t++){
                bool incl=0;
                if(t-arr[idx]>=0){
                       incl=dp[idx+1][t-arr[idx]];
                }
                bool excl=dp[idx+1][t];
        
                dp[idx][t]= incl || excl;
               
            }
        }
        return dp[0][target];
        
        
    }
    
    
     bool solvese(vector<int>& arr,int n,int target){
         vector<int> curr(target+1,0);
          vector<int> next(target+1,0);
         curr[0] = 1;
next[0] = 1;
        
        
        for(int idx=n-1;idx>=0;idx--){
            for(int t=0;t<=target;t++){
                bool incl=0;
                if(t-arr[idx]>=0){
                       incl=next[t-arr[idx]];
                }
                bool excl=next[t];
        
               curr[t]= incl || excl;
               
            }
            next=curr;
        }
        return next[target];
        
        
    }
    bool equalPartition(vector<int>& arr) {
        
        
       
        int n=arr.size();
        int total=0;
        
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        if(total & 1){
            return 0;
        }
        
        int target=total/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
       
        return solvese(arr,n,target);
    }
};