#include <iostream>
using namespace std;

void swapMaxMin(int arr[],int size){
	int b=INT_MIN , max;
	int c=INT_MAX,min;
	for(int i=0;i<size;i++){
		if(b<arr[i]){
			b=arr[i];
			max=i;
	}
	
	if(c>arr[i]){
			c=arr[i];
			min=i;
	}
	}
	
	swap(arr[max],arr[min]);
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	return;
}

int main(){
	int arr[]={1,2,3,4,5,6};
	
	swapMaxMin(arr,6);
	
	
	
}