#include <limits.h>
#include <vector>
int solver(int n,int x,int y,int z){
	if(n==0) return 0;

	if(n<0) return INT_MIN;


	int a=solver(n-x,x,y,z)+1;
	int b=solver(n-y,x,y,z)+1;
	int c=solver(n-z,x,y,z)+1;

	int ans= max(a,max(b,c));
	return ans;
}


int solvermemo(int n,int x,int y,int z,vector<int> &dp){
	if(n==0) return 0;

	if(n<0) return INT_MIN;
     
	if(dp[n]!=-1){
		return dp[n];
	}

	int a=solvermemo(n-x,x,y,z,dp)+1;
	int b=solvermemo(n-y,x,y,z,dp)+1;
	int c=solvermemo(n-z,x,y,z,dp)+1;

	dp[n]= max(a,max(b,c));
	return dp[n];
}

int solvertab(int n,int x,int y,int z){
	vector<int> dp(n+1,INT_MIN);

	dp[0]=0;

	for(int i=1;i<=n;i++){
		if(i-x >= 0 && dp[i-x] != INT_MIN)
            dp[i] = max(dp[i], dp[i-x] + 1);

        if(i-y >= 0 && dp[i-y] != INT_MIN)
            dp[i] = max(dp[i], dp[i-y] + 1);

        if(i-z >= 0 && dp[i-z] != INT_MIN)
            dp[i] = max(dp[i], dp[i-z] + 1);
	}

	if(dp[n]>=0){
		return dp[n];
	}else{
		return 0;
	}
}


int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1,-1);

	return solvertab(n,x,y,z);
	
	
}