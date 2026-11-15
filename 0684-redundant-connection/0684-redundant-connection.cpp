class Solution {
public:
    vector<int>parent,rank;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int u,int v){
        int pu=find(u);
        int pv=find(v);

        if(rank[pu]<rank[pv]){
           parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)) {
                return edge;
            }

            Union(u, v);
        }

        return {};
    }
};