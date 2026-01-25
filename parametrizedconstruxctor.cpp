#include <iostream>
#include <string>

using namespace std;


class Teacher{
	
	private:
		double salary;
	public:
		//non parameterized 
		Teacher(){
			cout<<"constructor is called\n";
			dept="cs";
		}
		
		// parameterized 
		Teacher(string n,string d ){
			name=n;
			dept=d;
		}
		string name;
		string dept;
		string subject;
	
		
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
	
	cout<<t1.name<<endl;
	
	cout<<t1.dept<<endl;
	

	
	
}