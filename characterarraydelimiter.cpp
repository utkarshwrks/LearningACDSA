#include <iostream>
using namespace std;

int main(){
//	char str[]={'a','b','c','\0'};
    char str[100];
    cout<<"enter sentence ="<<endl;
	cin.getline(str,100,'$');
	cout<<str;
} 