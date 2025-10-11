#include <iostream>
using namespace std;


int main(){
	int arr[5]={99,90,98,87,67};
	int b=INT_MAX;
	int min=0;
	int size = sizeof(arr)/ sizeof(int);
	
	
	for(int i=0;i<size;i++){
		if(b>arr[i]){
			b=arr[i];
			min=i;
	}

//       b=min(b,arr[i]);
	
}

cout<<b<<endl<<min;
}