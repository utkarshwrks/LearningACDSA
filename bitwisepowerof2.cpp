#include <iostream>
using namespace std;


bool power(int n){
	return (n>0 &(n & (n-1))==0);
}

int main(){
	cout<<power(8)<<endl;
}