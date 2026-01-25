#include <iostream>
#include <vector>
#include <list>

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
        l[u].push_back(v); // directed edge
    }

    bool isCycleDirDFS(int cur, vector<bool> &vis, vector<bool> &recpath) {
        vis[cur] = true;
        recpath[cur] = true;

        for (int v : l[cur]) {
            if (!vis[v]) {
                if (isCycleDirDFS(v, vis, recpath))
                    return true;
            }
            else if (recpath[v]) {
                return true; // back-edge found
            }
        }

        recpath[cur] = false; // backtrack
        return false;
    }

    bool isCycle() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleDirDFS(i, vis, recPath))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // creates a cycle

    if (g.isCycle())
        cout << "Cycle detected in directed graph\n";
    else
        cout << "No cycle in directed graph\n";

    return 0;
}
