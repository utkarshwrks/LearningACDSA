#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	

	
	vector <pair<int,int>> vec ={{1,2},{3,2},{2,6}};
    sort(vec.begin(),vec.end());
	for(auto p: vec){
		cout<< p.first << " "<<p.second<<endl; 
	}
	
	
}