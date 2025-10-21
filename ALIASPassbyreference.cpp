#include <iostream>
#include <vector>
using namespace std;

void changeA(int &b){//passbyrefernceusing ALIAS
	b =20;
}

int main(){
	
	int a=10;
	
	changeA(a);
	cout<<"inside main fun :"<<a<<endl;
	
	

}