#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
	list <int> l={1,2,3,4,5};
	l.push_back(6);
	l.push_front(0);
	
	l.pop_back();
	l.pop_front();
	for(int val:l){
		cout<<val<<" ";
	}
	
	
}