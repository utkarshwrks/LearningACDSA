class Solution {
public:
    vector<int> parent,rank;
    int findbaap(int a){
        if(parent[a]==a) return a;
        return parent[a]=findbaap(parent[a]);
    }

    void Union(int a,int b){
          a=findbaap(a);
          b=findbaap(b);
          if(a==b) return;
          if(rank[a]>rank[b]){
            parent[b]=a;
          }else if(rank[a]<rank[b]){
            parent[b]=a;
          }else{
            parent[a]=b;
            rank[a]++;
          }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) parent[i] = i;


        unordered_map<string, int> mp;
        
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=1;j<m;j++){
                string it=accounts[i][j];
                if(mp.find(it)==mp.end()){
                    mp[it]=i;
                }else{
                    Union(mp[it],i);
                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto &it : mp){
            int root=findbaap(it.second);
            merged[root].push_back(it.first);
        }
        vector<vector<string>> ans;
         for(int i=0;i<n;i++){
            if(merged[i].empty()){
                continue;
            }

            sort(merged[i].begin(),merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &it : merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
         }
         return ans;


    }
};