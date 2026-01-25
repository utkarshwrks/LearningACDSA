#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // BFS helper for cycle detection
    bool isCycleUndirectedBFS(int src, vector<bool> &vis) {
        
		queue <pair<int,int>> q;
		
		q.push({src,-1});
		vis[src] = true;
		
		while(!q.empty()){
			int u=q.front().first;
			int par=q.front().second;
			
			q.pop();
			
			list<int> neighbor=l[u];
			for(int v : neighbor){
				if(!vis[v]){
						q.push({vis[v],par});
					vis[v]=true;
				
				}else if(v!=par){
					return true;
				}
			}
		}

       
        return false;
    }

    bool isCycle() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUndirectedBFS(i, vis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    if (g.isCycle())
        cout << "Cycle exists";
    else
        cout << "No cycle";

    return 0;
}
