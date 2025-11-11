#include <iostream>
using namespace std;


int getmaxSum(int matrix[][3],int row, int col){
	int maxrowsum=INT_MIN;
	for(int i=0;i<row;i++){
	   int maxirow=0;
		for(int j=0;j<col;j++){
		  maxirow+=matrix[i][j];
		}
		maxrowsum=max(maxrowsum,maxirow);
		
	}
	return maxrowsum;
}

int main(){
	int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int row=4;
	int col=3;
	cout<<getmaxSum(matrix,row,col);

}