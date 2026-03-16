#include <bits/stdc++.h> 

int solve(vector<int>& weight, vector<int>& value, int index, int capacity){
    if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}else{
			return 0;
		}
	}

    int include=0;
	if(weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	}


	int exclude=solve(weight,value,index-1,capacity-weight[index]);


	int ans=max(include,exclude);
	return ans;
}


int solvememo(vector<int>& weight, vector<int>& value,
              int index, int capacity, vector<vector<int>> &dp) {

    if(index == 0){
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if(dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] +
                  solvememo(weight, value, index-1,
                            capacity-weight[index], dp);
    }

    int exclude = solvememo(weight, value, index-1, capacity, dp);

    return dp[index][capacity] = max(include, exclude);
}


int solvetab(vector<int>& weight, vector<int>& value,
             int n, int maxWeight) {

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // base case
    for (int w = 0; w <= maxWeight; w++) {
        if (weight[0] <= w)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++) {
        for (int w = 0; w <= maxWeight; w++) {

            int include = 0;
            if (weight[index] <= w)
                include = value[index] +
                          dp[index - 1][w - weight[index]];

            int exclude = dp[index - 1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[n - 1][maxWeight];
}



int solvetabso(vector<int>& weight, vector<int>& value,
             int n, int capacity) {

    vector<int> prev(capacity+1,0);
     vector<int> cur(capacity+1,0);
    


    // base case
    for (int w = 0; w <= capacity; w++) {
        if (weight[0] <= w)
           prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++) {
        for (int w = 0; w <=capacity; w++) {

            int include = 0;
            if (weight[index] <= w)
                include = value[index] +
                         prev[w - weight[index]];

            int exclude = prev[w];

           cur[w] = max(include, exclude);
        }
        prev =cur;
    }

    return prev[capacity];
}


int solvetabsoMORE(vector<int>& weight, vector<int>& value,
                   int n, int capacity) {

    vector<int> cur(capacity + 1, 0);

    // base case: first item
    for (int w = weight[0]; w <= capacity; w++) {
        cur[w] = value[0];
    }

    for (int index = 1; index < n; index++) {
        for (int w = capacity; w >= 0; w--) {   // ?? reverse loop
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + cur[w - weight[index]];

            int exclude = cur[w];

            cur[w] = max(include, exclude);
        }
    }

    return cur[capacity];
}

int knapsack(vector<int> weight, vector<int> value,
             int n, int maxWeight) {
    return solvetabsoMORE(weight, value, n, maxWeight);
}