#include <iostream>
using namespace std;

//int binomial(int n,int r){
//	 int factn=1,factr=1,factnr=1;
//	 for(int i=1;i<=n;i++){
//	 	factn=factn*i;
//	 }
//	 for(int i=1;i<=r;i++){
//	 	factr=factr*i;
//	 }
//	 for(int i=1;i<=(n-r);i++){
//	 	factnr=factnr*i;
//	 }
//	 
//	 int cb=factn/(factr*factnr);
//	 return cb;
//
//}


int fact(int n){
	int fact=1;
	for(int i=1;i<=n;i++){
		fact=fact*i;
	}
	return fact;
}


int ncr(int n,int r){
	int factn=fact(n);
	int factr=fact(r);
	int factnmr=fact(n-r);
	

	
	return factn/(factr*factnmr);
	
}



int main(){

	cout<<ncr(6,3)<<endl;
	
	
	return 0;
	
}