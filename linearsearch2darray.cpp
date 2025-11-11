#include <iostream>
using namespace std;

int main(){
	int matrix[4][3];
	int row=4;
	int col=3;
	int num;
	cin>>num;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>matrix[i][j];
		}
	
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(matrix[i][j]==num){
				cout<<"founded"<<"i= "<<i<<"j= "<<j<<endl;
			}
		}
		
	}
}