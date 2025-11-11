#include <iostream>
using namespace std;


int diagonalSum(int matrix[][3],int row, int col){
	int sum=0;
	for(int i =0;i<row;i++){
		sum+=matrix[i][i];
	if(i!=col-i-1){
		sum+=matrix[i][col-i-1];
	}
	}
	return sum;
}

int main(){
	int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int row=3;
	int col=3;
	cout<<diagonalSum(matrix,row,col);

}