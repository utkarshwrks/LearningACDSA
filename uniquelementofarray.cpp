#include <iostream>
using namespace std;

void uniqueElement(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
}

int main(){
	int arr[]=  {1,2,3,1,2,3,3,4,3,5};
	
	uniqueElement(arr,10);
}