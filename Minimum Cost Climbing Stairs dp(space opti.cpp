class Solution {
public: 
    int solver(vector<int>& cost,int n){
        
       int prev2=cost[0];
       int prev1=cost[1];
        for(int i=2;i<n;i++){
           int cur=cost[i]+min(prev1,prev2);
           prev2=prev1;
           prev1=cur;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        return solver(cost,n);
    }
};