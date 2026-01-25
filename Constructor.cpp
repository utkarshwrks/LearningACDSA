#include <iostream>
#include <string>

using namespace std;


class Teacher{
	
	private:
		double salary;
	public:
		
		Teacher(){
			cout<<"constructor is called\n";
			dept="cs";
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
	Teacher t1;//constructor call
	t1.name="Suresh";
	t1.subject="c++";
	
	t1.setSalary(50000);
	cout<<t1.name<<endl;
	
	cout<<t1.dept<<endl;
	
	cout<<t1.getsalary()<<endl;
	
	
}