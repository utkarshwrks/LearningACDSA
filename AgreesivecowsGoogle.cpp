#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool Possible(vector <int> arr, int n, int c,int minAlloweddistance){
	
	int cows=1,lastposition=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]-lastposition>=minAlloweddistance){
			cows++;
			lastposition=arr[i];
		}
		if(cows==c) return true;
	}
	return false;
}

int getDistance(vector <int> &arr, int n, int c){
	sort(arr.begin(),arr.end());
	
	int start=1,end=arr[n-1]-arr[0],ans=-1;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		
		if(Possible(arr,n,c,mid)){
			ans=mid;
			start=mid+1;
		}else{
			
			end=mid-1;
		}
	}
	return ans;
}

int main(){
	vector <int> arr= {1,2,8,4,9};
	int n=5, c=3;
	
	cout<<getDistance(arr,n,c)<<endl;
	
	
}