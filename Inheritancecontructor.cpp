#include <iostream>
using namespace std;

class Person{
    public:
	   string name;
	   int age;
	   
	   Person(string name,int age){
	   	
	   	this->name=name;
	   	this->age=age;
	   
	   	
	   }
	   
	   ~Person(){
	   	
	   	cout<<"person destructror called"<<endl;
	   	
	   }	
};


class Student: public Person{
	
	public:
		int roll;
		
		Student(string name,int age,int roll) : Person(name, age)
{
			this->roll=roll;
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
	Student s1("suresh",12,123);

	s1.getInfo();
}