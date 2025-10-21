#include <iostream>
#include <vector>
using namespace std;


int main(){
	
	int arr[]={1,2,3,4,5};
	
	cout<<arr<<endl;//adress
    cout<<*arr<<endl;	//value og oth index
	cout<<*(arr+1)<<endl;//adding in adress
	cout<<*(arr+2)<<endl;
	cout<<*(arr+3)<<endl;
	cout<<*(arr+4)<<endl;

}