#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;


void dfs(int node, unordered_map<int,bool> &vis,
         stack<int> &s,
         unordered_map<int,list<int>> &adj){

    vis[node] = true;

    for(auto v : adj[node]){
        if(!vis[v]){
            dfs(v, vis, s, adj);
        }
    }

    s.push(node);
}

void revdfs(int node,
            unordered_map<int,bool> &vis,
            unordered_map<int,list<int>> &trf){

    vis[node] = true;

    for(auto v : trf[node]){
        if(!vis[v]){
            revdfs(v, vis, trf);
        }
    }
}

int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;

    // Step 1: Build graph
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int to = edges[i][1];
        adj[u].push_back(to);
    }

    stack<int> s;
    unordered_map<int,bool> vis;

    // Step 2: Fill stack by finish time
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, vis, s, adj);
        }
    }

    // Step 3: Create transpose graph
    unordered_map<int,list<int>> trf;

    for(int i=0;i<V;i++){
        vis[i] = false;
        for(auto nbr : adj[i]){
            trf[nbr].push_back(i);
        }
    }

    // Step 4: Count SCC
    int count = 0;

    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(!vis[top]){
            count++;
            revdfs(top, vis, trf);
        }
    }

    return count;
}
