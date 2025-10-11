#include <iostream>
using namespace std;



//for loop two pointer
void reverseArr(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//while loop


//void reverseArr(int arr[],int size){
//	int start=0,end=size-1;
//	while(start<end){
//		swap(arr[start],arr[end]);
//		start++;
//		end--;
//	}
//	
//	for (int i = 0; i < size; i++) {
//       cout << arr[i] << " ";
//    }
//    cout << endl;
//}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6,7};
    reverseArr(arr, 7);
    return 0;
}
