class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int  n=prices.size();
        
        sort(prices.begin(),prices.end());
        
        
        int mini=0;
        int buy=0;
        int free=n-1;
        
        while(buy<= free){
            mini=mini+prices[buy];
            buy++;
            free=free-k;
        }
        
        
        int maxi=0;
         buy=n-1;
         free=0;
        
        while(free<=buy){
            maxi=maxi+prices[buy];
            buy--;
              free=free+k;
        }
        
        return {mini,maxi};
    }
};