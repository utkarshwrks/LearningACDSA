#include <iostream>
#include <vector>
using namespace std;

int main(){


    vector<int>vec ;
    //size
    cout<<"size = "<<vec.size()<<endl;
    //push_back
    vec.push_back(25);
    vec.push_back(35);
    vec.push_back(45);
    
    
     cout<<" after push back size = "<<vec.size()<<endl;
     //pop_back
     vec.pop_back();
     
     cout<<" after pop back size = "<<vec.size()<<endl;
     
     
     //front 
     cout<<" front value = "<<vec.front()<<endl;
     //back
     cout<<" back value = "<<vec.back()<<endl;
     //at
     cNout<<" particular index value = "<<vec.at(0)<<endl;
    
    for(int val : vec){
    	cout << val <<endl;
	}

		
}