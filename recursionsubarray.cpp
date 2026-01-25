#include <iostream>
#include <vector>
using namespace std;

void printSubarr(vector<int> &arr, vector<int> &ans,int i){
	 
	 if(i==arr.size()){
	 	for(int val : ans){
	 		cout<<val<<" ";
		 }
		 cout<<endl;
		 return;
	 }
	 
	 //include 
	 ans.push_back(arr[i]);
	 printSubarr(arr,ans,i+1);
	 
	 //exclude
	 ans.pop_back();
	 printSubarr(arr,ans,i+1);
	 
	
	
	
}

int main(){
	vector<int> arr={1,2,3};
	vector<int> ans;
	
	printSubarr(arr,ans,0);
	
}