#include <iostream>
using namespace std;

int dec(int n){
	int ans=0,pow=1;
	
	while(n>0){
		int rem=n%10;
		n=n/10;
		ans=ans+(rem*pow);
		pow=pow*2;
	    
	}
	return ans;
}

int main(){
	cout<<dec(110)<<endl;
}