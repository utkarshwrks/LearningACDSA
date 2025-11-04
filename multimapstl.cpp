#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
	multimap <string,int> m;

	
	m.emplace("camera",25);
		m.emplace("camera",25);
			m.emplace("camera",25);
				m.emplace("camera",25);
				
	m.erase(m.find("camera"));
	
	
	
	for(auto p: m){
		cout<<p.first<< " "<<p.second<<endl; 
	}
	
	
}