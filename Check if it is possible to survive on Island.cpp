class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        
        // If we cannot even meet one day's requirement
        if(M > N) return -1;
        
        int sunday = S / 7;
        int buyingDays = S - sunday;
        
        int totalFood = S * M;
        
        // Minimum days needed to buy food
        int ans = (totalFood + N - 1) / N;
        
        if(ans <= buyingDays){
            return ans;
        }
        
        return -1;
    }
};