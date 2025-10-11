#include <iostream>
using namespace std;

void fibonaci(int n){
	int facb, a=0,b=1;
	
	 cout << a << " " << b << " ";
	for(int i=1;i<=n;i++){
		facb=a+b;
		
		cout<<facb<<" ";
		
		a=b;
		b=facb;
		
	}
	return;
	
	
}
int main(){
	fibonaci(4);
	
}