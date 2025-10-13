#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n=5;
	int arr[5]={1,2,3,4,5};
	int maxSum= INT_MIN;
	
	for(int start=0;start<n;start++){
		int cursum=0;
		for(int end=start;end<n;end++){
			cursum += arr[end];
			maxSum = max(cursum,maxSum);
		}
	}
	cout<<maxSum;
}