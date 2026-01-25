#include <iostream>
#include <string>
using namespace std;

class Print{
	
	public:
	
		
		
		void show(int x){
			cout<<"int: "<<x<<endl;
		}
		
		void show(char x){
			cout<<"char: "<<x<<endl;
		}
};

int main(){
	Print p1;
	p1.show(2);

}