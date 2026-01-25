#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int cursize, cap;
    int f, r;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        cursize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (cursize == cap) {
            cout << "full hogai" << endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        cursize++;
    }

    void pop() {
        if (empty()) {
            cout << "khali hogai" << endl;
            return;
        }
        f = (f + 1) % cap;
        cursize--;

        // reset when empty
        if (cursize == 0) {
            f = 0;
            r = -1;
        }
    }

    int front() {
        if (empty()) {
            cout << "khali hogai" << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return cursize == 0;
    }

    // destructor to avoid memory leak
    ~CircularQueue() {
        delete[] arr;
    }
};
int main() {
    CircularQueue q(3);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl; // 10
    q.pop();

    cout << q.front() << endl; // 20
    q.pop();

    q.push(40);
    cout << q.front() << endl; // 30

    return 0;
}
