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

    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];

        // Step 2: Reduce size
        size--;

        // Step 3: Heapify
        int i = 1;

        while(i <= size) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if(left <= size && arr[left] > arr[largest])
                largest = left;

            if(right <= size && arr[right] > arr[largest])
                largest = right;

            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
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
