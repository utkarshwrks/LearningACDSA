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
	


    vector <int> vec ={4,5,3,8,2};
//    reverse(vec.begin(),vec.end());//whole revrse

     reverse(vec.begin()+1,vec.begin()+3);//reverse 3,5
	
	
	for(int val: vec){
		cout<< val << " "<<endl; 
	}
	
	
}