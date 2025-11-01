#include <iostream>
using namespace std;

void SelectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int smallestidx=i;
		for(int j=i+1;j<n-1;j++){
			if(arr[j]<arr[smallestidx]){
				smallestidx=j;
			}
			swap(arr[i],arr[smallestidx]);
		}
	}
}

void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
 

int main(){
	
	int n=5;
	int arr[]={4,1,3,2,5};
	
	SelectionSort(arr,n);
	printArr(arr,n);
}