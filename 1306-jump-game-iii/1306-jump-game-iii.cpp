class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<int>& vis){
        if(start < 0 || start >= arr.size() || vis[start]){
            return false;
        }

        if(arr[start] == 0){
            return true;
        }

        vis[start] = 1;

        return dfs(arr, start + arr[start], vis) ||
               dfs(arr, start - arr[start], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);

        if(arr[start] == 0){
            return true;
        }

        return dfs(arr, start, vis);
    }
};