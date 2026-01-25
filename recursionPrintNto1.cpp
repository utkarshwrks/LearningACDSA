#include <iostream>
using namespace std;

void printnums(int n){
	if(n==1){
		cout<<"1\n";
		return;
	}
	
	cout<<n<<" ";
	
	printnums(n-1);
}
int main(){
	printnums(10000);
}