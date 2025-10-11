#include <iostream>
using namespace std;

int main(){
	int a[10],b=0,n;
	cout<<"entrsize"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
				
			}
		}
	}
	cout<<a[n-1];
}