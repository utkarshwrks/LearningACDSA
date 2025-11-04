#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int main(){
set<int> s;
s.emplace(1);
s.emplace(2);
s.emplace(31);
s.emplace(4);
s.emplace(15);


cout<<"lower bound ="<<*(s.lower_bound(4))<<endl;
cout<<"upper bound ="<<*(s.upper_bound(4))<<endl;


	
	
	for(int val: s){
		cout<< val << " "<<endl; 
	}
	
	
}