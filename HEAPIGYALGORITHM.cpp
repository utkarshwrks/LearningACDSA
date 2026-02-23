#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Upward heapify
        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Downward heapify
    void heapify(int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= size && arr[left] > arr[largest])
            largest = left;

        if(right <= size && arr[right] > arr[largest])
            largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        heapify(1);
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    heap h;
    h.insert(50);
    h.insert(55);   
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Before deletion: ";
    h.print();

    h.deleteFromHeap();

    cout << "After deletion: ";
    h.print();

    return 0;
}


//
//#include <iostream>
//using namespace std;
//
//void heapify(int arr[], int n, int i) {
//    int largest = i;
//    int left = 2 * i;
//    int right = 2 * i + 1;
//
//    if(left <= n && arr[left] > arr[largest])
//        largest = left;
//
//    if(right <= n && arr[right] > arr[largest])
//        largest = right;
//
//    if(largest != i) {
//        swap(arr[i], arr[largest]);
//        heapify(arr, n, largest);
//    }
//}
//
//int main() {
//
//    int arr[6] = {-1, 54, 53, 55, 52, 50};
//    int n = 5;
//
//    // Build Heap (O(n))
//    for(int i = n/2; i > 0; i--) {
//        heapify(arr, n, i);
//    }
//
//    cout << "Printing the array now:\n";
//    for(int i = 1; i <= n; i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}
