#include <iostream>
using namespace std;

class Person{
    public:
	   string name;
	   int age;
	   
	   Person(){
	   	
	   	cout<<"person called"<<endl;
	   	
	   }
	   
	   ~Person(){
	   	
	   	cout<<"person destructror called"<<endl;
	   	
	   }	
};


class Student: public Person{
	
	public:
		int roll;
		
		Student(){
			cout<<"student called"<<endl;
		}
		
	    void getInfo(){
	    	cout<<"name: "<<name<<endl;
	    	cout<<"age: "<<age<<endl; 
	    	cout<<"rollno: "<<roll<<endl;
		}
		
		~Student(){
			cout<<"student destructor called"<<endl;
		}
};


int main(){
	Student s1;
	s1.name="suresh";
	s1.age=12;
	s1.roll=123;
	s1.getInfo();
}