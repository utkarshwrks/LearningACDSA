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
	
//	int arr[5]={4,5,3,8,2};
//	sort(arr,arr+5);

//    vector <int> vec ={4,5,3,8,2};//asending
//    sort(vec.begin(),vec.end());

//
//     sort(vec.begin()+1,vec.begin()+3);//sort in range of 5,3
	
	vector <int> vec ={4,5,3,8,2};
    sort(vec.begin(),vec.end(),greater<int>());//descending
	for(int val: vec){
		cout<< val << " "<<endl; 
	}
	
	
}