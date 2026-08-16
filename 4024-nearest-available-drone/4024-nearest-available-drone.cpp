class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
       int n =drones.size();
         int ans = -1;
        int minDist = INT_MAX;
        for(int i=0;i<n;i++){
            int demo=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(demo<=drones[i][2]){
               if(demo<minDist){
                    minDist=demo;
                   ans=i;
               }
            }
        }
       
        return ans;
    }
};