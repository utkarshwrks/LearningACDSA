#include <iostream>
using namespace std;

int sumofDigits(int n){
	int sumdig=0;
	
	while(n>0){
		int lastDig=n%10;
		n=n/10;
		sumdig=sumdig+lastDig;
	}
	return sumdig;
}

int main(){

	cout<<sumofDigits(145)<<endl;
	
	
	return 0;
	
}