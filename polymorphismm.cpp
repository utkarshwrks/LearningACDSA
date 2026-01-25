#include <iostream>
#include <string>
using namespace std;

class Student{
	
	public:
		string name;
		
		
		Student(){
			cout<<"desi";
		}
		
		Student(string name){
			this->name=name;
			cout<<"parametrized";
		}
};

int main(){
	Student s1("suresh");

}