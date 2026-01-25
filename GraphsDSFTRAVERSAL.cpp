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

    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfshelper(int u, vector<bool>& vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) {
                dfshelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);
        dfshelper(0, vis);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
     
    g.addEdge(2, 4);

    g.dfs();  // DFS
    g.bfs(); // BFS
}
