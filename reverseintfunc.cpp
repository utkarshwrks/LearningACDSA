#include <iostream>
using namespace std;


int reverseInt(int n){
	
	int t=0 , p=0;
	while(n>0){
		t=n%10;
		
		p=p*10+t;
		n=n/10;
		
	}
	return p;
}


int main(){
	cout<<reverseInt(145)<<endl;
}