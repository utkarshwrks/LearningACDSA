#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];   // FIX
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    
    void bsf(){
    	queue <int> q;
    	vector<bool> vis(V,false);
    	
    	q.push(0);
    	
    	vis[0]=true;
    	
    	while(!q.empty()){
    		int u=q.front();
    		
    		q.pop();
    		
    		cout<<u<<" ";
    		
    		for(int v : l[u]){
    			if(!vis[v]){
    				vis[v]=true;
    				q.push(v);
				}
			}
		}
		cout<<endl;
    	
    	
	}

    
};

int main() {

    Graph g(5);  // FIX
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    
    g.bsf();

    
}
