#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
	map <string,int> m;
	m["tv"]=100;
	m["headphone"]=50;
	m["tablets"]=54;
	m["ac"]=80;
	
	m.emplace("camera",25);
	
	
	
	for(auto p: m){
		cout<<p.first<< " "<<p.second<<endl; 
	}
	cout<<"count laptop ="<<m.count("laptop")<< endl;
	
	if(m.find("camera")!=m.end()){
		cout<<"found\n";
	}else{
		cout<<"notfound\n";
	}
	
	
}