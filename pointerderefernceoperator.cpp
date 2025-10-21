#include <iostream>
#include <vector>
using namespace std;

int main(){
	int a = 10;
	int* ptr=&a;

	cout<< *(&a) << endl;//(yaha adress ki)1o because at this adress value is 10
	cout<< *(ptr)<< endl;//(yaha value ki baat ho rahi h)10 because it store the adress of a as a value
	cout<< *(&ptr)<< endl;//adress of a beause in this adress the adress of a is stored
	
}