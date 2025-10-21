#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> arr, int target){//iterative
	int n=arr.size();
	int str=0,end=n-1;
	while(str<=end){
		int mid = (str+end)/2;
		
		if(target>arr[mid]){
			str=mid+1;
		}
		else if(target<arr[mid]){
			end=mid-1;
		}else{
			return mid;
		}
	}
	return -1;
}

int main(){
	vector<int> arr1={-1,0,3,4,5,9,12};
	int tar1=12;
	cout<<"arr1"<<binarySearch(arr1,tar1);
	
	vector<int> arr2={-1,0,3,4,5,12};
	int tar2=0;
	cout<<"arr2"<<binarySearch(arr2,tar2);
}