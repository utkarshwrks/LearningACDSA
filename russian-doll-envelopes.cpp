class Solution {
public:
    int solve(vector<vector<int>>& arr){
        int n=arr.size();
        if(n==0) return 0;

        vector<int> ans;
        ans.push_back(arr[0][1]);

        for(int i=1;i<n;i++){
            if(arr[i][1]>ans.back()){
                 ans.push_back(arr[i][1]);
            }else{
                 int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[index]=arr[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        return solve(arr);
    }
};