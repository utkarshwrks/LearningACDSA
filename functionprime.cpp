#include <iostream>
using namespace std;

void checkPrimeno(int n){
	int t =0;
	for(int i=2;i*i<=n;i++){
		t=n%i;
	}
	if(t!=0){
		cout<<"no. usprime";
		return;
	}
	else{
		cout<<"not prime";
		return;
	}
}
int main(){
	checkPrimeno(5);
}