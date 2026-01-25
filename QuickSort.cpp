#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int> &arr,int start,int end){
	
	int idx=start-1;
	int pivot=arr[end];
	
	for(int j=start;j<end;j++){
		if(arr[j]<=pivot){
			idx++;
			swap(arr[idx],arr[j]);
		}
	}
	idx++;
	swap(arr[idx],arr[end]);
	
	return idx;
}

void quickSort(vector<int> &arr,int start,int end){
	int pivotIdx;
	if(start<end){
		pivotIdx=partition(arr,start,end);
	
	quickSort(arr,start,pivotIdx-1);
	quickSort(arr,pivotIdx+1,end);
	}
}



int main(){
	
	vector<int> arr={8,7,3,9,5,4};
	quickSort(arr,0,arr.size()-1);
	for(int val : arr){
		cout<<val<<" ";
	}
}