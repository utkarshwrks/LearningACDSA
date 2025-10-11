#include <iostream>
using namespace std;

int minTwono(int a, int b){ //parameter
	if(a>b){
		cout<<"a is greater"<<endl;
		return a;
	}
	else{
		cout<<"b is greater"<<endl;
		return b;
	}
}

int main(){
	cout<< minTwono(4,5)<<endl;//argument
}