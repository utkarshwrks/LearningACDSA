#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main(){
	deque <int> d={1,2,3,4,5};
	d.push_back(6);
	d.push_front(0);
	
	d.pop_back();
	d.pop_front();
	for(int val:d){
		cout<<val<<" ";
	}
	
	
}