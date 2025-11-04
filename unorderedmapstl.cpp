#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map<string,int> m;

	
	m["tv"]=100;
	m["headphone"]=50;
	m["tablets"]=54;
	m["ac"]=80;
	
	
	
	for(auto p: m){
		cout<<p.first<< " "<<p.second<<endl; 
	}
	
	
}