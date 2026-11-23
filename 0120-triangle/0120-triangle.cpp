class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev=triangle[0];
       
       

        for (int i = 1; i < n; i++) {
            int m = triangle[i].size();
            vector<int> cur=triangle[i];
            for (int j = 0; j <= i; j++) {
                if(j==0){
                    cur[j]+=prev[j];
                }else if(j==i){
                    cur[j] += prev[j-1];
                }else{
                    cur[j]+=min(prev[j],prev[j-1]);
                }

            }
            prev=cur;
            
            
        }
        return *min_element(prev.begin(), prev.end());
    }
};