#include <iostream>
using namespace std;

void sumAndproduct(int arr[],int size ){
	int sum=0;
	int prod=1;
	for(int i=0;i<size;i++){
		sum=sum+arr[i];
		prod=prod*arr[i];
		
	}
	
	cout<<"Product = "<<prod<<endl;
	cout<<"Sum = "<<sum<<endl;
	return;
}

int main(){
	int arr[]={1,2,3,4,5};
    sumAndproduct(arr,5);
}