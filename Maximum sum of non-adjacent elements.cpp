#include <bits/stdc++.h> 
using namespace std;

int solver(vector<int> &nums,int n){
    if(n<0) return 0;

    if(n==0) return nums[0];

    int inclu=solver(nums,n-2)+nums[n];
    int exclu=solver(nums,n-1)+0;

    return max(inclu,exclu);
}

int solvermemo(vector<int> &nums,int n, vector<int> &dp){
    if(n<0) return 0;

    if(n==0) return nums[0];
    

    if(dp[n]!=-1) return dp[n];
    int inclu=solvermemo(nums,n-2,dp)+nums[n];
    int exclu=solvermemo(nums,n-1,dp)+0;

    dp[n]= max(inclu,exclu);
    return dp[n];
}


int solvertab(vector<int> &nums){

  int n=nums.size();
   
    if (n == 0) return 0;
    if (n == 1) return nums[0];

     vector<int> dp(n,0);

     dp[0]=nums[0];

     for(int i=1;i<n;i++){
       int inclu=dp[i-2]+nums[i];
       int exclu=dp[i-1]+0;
       dp[i]= max(inclu,exclu);

     }
     return dp[n-1];
    

}





int solvertabo(vector<int> &nums){

  int n=nums.size();
   
    if (n == 0) return 0;
    if (n == 1) return nums[0];

     vector<int> dp(n,0);

   int prev2=0;
   int prev1=nums[0];
     for(int i=1;i<n;i++){
       int inclu=prev2+nums[i];
       int exclu=prev1+0;
       int ans= max(inclu,exclu);

       prev2=prev1;
       prev1=ans;

     }
     return prev1;
    

}

int maximumNonAdjacentSum(vector<int> &nums){
  int n=nums.size();
 
  int ans=solvertabo(nums);
  return ans;
}