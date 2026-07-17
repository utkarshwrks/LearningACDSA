class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> od(n+1,0);
       vector<int> id(n+1,0);

       for(auto it : trust){
        od[it[0]]++;
        id[it[1]]++;
       }

        for(int i=1;i<=n;i++){
            if(od[i]==0 && id[i]==n-1){
                return i;
            }
        }
        return -1;

    }
};