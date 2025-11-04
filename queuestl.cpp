#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main(){
	priority_queue <int> q;
//	priority_queue <int, vector <int>,greater <int>> q;//reserver priority
	q.push(5);
	q.push(10);
	q.push(3);
	
	while(!q.empty()){
		cout<<"top = "<<q.top()<<endl;
		q.pop();
	}
	cout<<"top = "<<q.top()<<endl;
	
	


}