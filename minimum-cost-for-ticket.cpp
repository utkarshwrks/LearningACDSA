class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int index) {
        if (index >= n) {
            return 0;
        }

        int option1 = costs[0] + solve(n, days, costs, index + 1);

        int i; // 7 days ke baad wale din k indx

        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int option2 = costs[1] + solve(n, days, costs, i);

        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;

        int option3 = costs[2] + solve(n, days, costs, i);

        return min(option1, min(option2, option3));
    }
    int solvememo(int n, vector<int>& days, vector<int>& costs, int index,
                  vector<int>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int option1 = costs[0] + solvememo(n, days, costs, index + 1, dp);

        int i; // 7 days ke baad wale din k indx

        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int option2 = costs[1] + solvememo(n, days, costs, i, dp);

        // 30 days ke baad wale din k indx
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;

        int option3 = costs[2] + solvememo(n, days, costs, i, dp);

        dp[index] = min(option1, min(option2, option3));

        return dp[index];
    }

    int solvetab(int n, vector<int>& days, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;

        for (int k = n - 1; k >= 0; k--) {
            int option1 = costs[0] + dp[k+1];

            int i; // 7 days ke baad wale din k indx

            for (i = k; i < n && days[i] < days[k] + 7; i++)
                ;

            int option2 = costs[1] + dp[i];

            // 30 days ke baad wale din k indx
            for (i = k; i < n && days[i] < days[k] + 30; i++)
                ;

            int option3 = costs[2] +dp[i];

            dp[k] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

    int ans = 0;

    queue<pair<int,int>> week;
    queue<pair<int,int>> month;

    for(int day : days){

        // Remove expired 7-day passes
        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }

        // Remove expired 30-day passes
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }

        // Add new pass options starting today
        week.push({day, ans + costs[1]});
        month.push({day, ans + costs[2]});

        // Choose minimum among:
        // 1-day pass
        // cheapest valid 7-day pass
        // cheapest valid 30-day pass
        ans = min({
            ans + costs[0],
            week.front().second,
            month.front().second
        });
    }

    return ans;
}
};