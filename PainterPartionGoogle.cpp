#include <iostream>
#include <vector>
using namespace std;

bool Valid(vector <int> arr, int n, int m,int mid){
	
	int days=0,painter=1;
	
	for(int i=0;i<n;i++){
		if(arr[i]>mid) return false;
		
		if(days+arr[i]<=mid){
			days+=arr[i];
		}else{
			days=arr[i];
			painter++;
		}
	}
	
	return(painter>m?false:true);
}

int painterPartion(vector <int> arr, int n, int m){
	
	int ans=0;
	int sum=0 ,maxVal=INT_MIN;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		start=max(arr[i],maxVal);
	}
	
	int  end=sum;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		
		if(m>n) return -1;
		
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
	vector <int> arr= {10,30,20};
	int n=3, m=2;
	
	cout<<painterPartion(arr,n,m)<<endl;
	
	
}