#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
    }

    void dfs(int node, unordered_map<int,bool> &vis, stack<int> &s){
        vis[node] = true;

        for(auto v : adj[node]){
            if(!vis[v.first]){
                dfs(v.first, vis, s);
            }
        }
        s.push(node);
    }
    
    void getShortest(int src, vector<int> &dist, stack<int> &s){
        dist[src] = 0;
    
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main() {

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    int n = 6;
    
    unordered_map<int,bool> vis;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            g.dfs(i, vis, s);
        }
    }

    int src = 1;
    vector<int> dist(n, INT_MAX);

    g.getShortest(src, dist, s);

    cout << "Shortest distances from source " << src << ":\n";
    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
}
