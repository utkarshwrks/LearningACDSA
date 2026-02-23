#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Top element: " << pq.top() << endl;

    cout << "All elements (largest to smallest): ";

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
