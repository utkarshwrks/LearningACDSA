#include <iostream>
using namespace std;

int sum(int a,int b){
	
	a=a+10;
	b=b+10;
	int sum=a+b;
	return sum;
	
}

//int main(){
//	int x=5;
//	int y=4;
//	cout<< sum(x,y)<<endl;//passbyvalue yeh copy bana r h 
//	cout<<x<<endl;//5
//	cout<<y<<endl;//4
//}

int main(){
	int a=5;
	int b=4;
	cout<< sum(a,b)<<endl;//passbyvalue yeh copy bana r h 
	cout<<a<<endl;//5
	cout<<b<<endl;//4
}