#include <iostream>
using namespace std;

int factofN(int n){
	int fact = 1;
	for(int i=1;i<=n;i++){
		fact=fact*i;
	}
	return fact;
}

int main(){
	cout<< factofN(5)<<endl;//argument
}