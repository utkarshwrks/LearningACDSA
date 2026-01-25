#include <iostream>
#include <string>

using namespace std;


class Teacher{
	
	private:
		double salary;
	public:
		
			string name;
		string dept;
		string subject;
	
		
		
		// parameterized 
		Teacher(string name,string dept ){
			this->name=name;
			this->dept=dept;
		}
	     
	    Teacher(Teacher &obj){
	        this->name=obj.name;
	        this->dept=obj.dept;
		}
		
		void changeDept(string newDept){
			dept=newDept;
		}
		
		void setSalary(double s){
			salary =s;
		}
		
		double getsalary(){
    return salary;
}

};

int main(){
	Teacher t1("suresh","cs");
	Teacher t2(t1);
	cout<<t2.name<<endl;
	
	cout<<t2.dept<<endl;
	

	
	
}