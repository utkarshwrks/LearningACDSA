#include <iostream>
using namespace std;

void InsertionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int cur = arr[i];
		int prev=i-1;
		
		while(prev >=0 && arr[prev]>cur){
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1]=cur;
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
	
	InsertionSort(arr,n);
	printArr(arr,n);
}