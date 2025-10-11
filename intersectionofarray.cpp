#include <iostream>
using namespace std;

void uniqueElement(int arr1[], int size1,int arr2[],int size2) {
    for (int i = 0; i < size1; i++) {


        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout<<arr1[i]<<endl;
            }
        }

    }
}

int main(){
	int arr1[]=  {1,2,3,4,5};
	int arr2[]= {6,7,1,3};
	
	uniqueElement(arr1,5,arr2,4);
}