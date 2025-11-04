#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;

int main(){
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	
//	while(!s.empty()){
//		cout<<"top = "<<s.top()<<endl;
//		s.pop();
//	}
//	cout<<"top = "<<s.top()<<endl;
	stack <int> s2;
	s2.swap(s);
	
	cout<<"sizze s ="<<s.size()<<endl;
	cout<<"sizze s2 ="<<s2.size()<<endl;
	
	
	

	
	
}