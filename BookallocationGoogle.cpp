#include <iostream>
#include <vector>
using namespace std;

bool Valid(vector <int> arr,int n, int m,int mid){
	int pages=0,student=1;

	for(int i=0;i<n;i++){
			if(arr[i]>mid){
		return false;
	}
		if(pages+arr[i]<=mid){
			pages+=arr[i];
		}else{
			pages=arr[i];
			student++;
		}
	}
	return student>m?false:true;
}

int allocationBooks(vector <int> arr,int n, int m){
	
	if(m>n){
		return -1;
	}
	
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
	}
	
	int start=0,end=sum;
	int ans=-1;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		if(Valid(arr,n,m,mid)){
			ans=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	
	return ans;
	
}

int main(){
	
	vector <int> arr={2,1,3,4};
	int n=4,m=2;
	
	cout<<allocationBooks(arr,n,m)<<endl;
  	
}