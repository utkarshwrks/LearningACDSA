#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;

int main(){
//	pair <int,int> p ={1,2};
    pair <int,pair<char,int>> p ={1,{'a',2}};
	cout<<p.first<<endl;
	cout<<p.second.first<<endl;
	cout<<p.second.second<<endl;
	
	
}