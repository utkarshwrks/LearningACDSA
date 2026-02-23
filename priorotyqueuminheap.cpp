#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Top element (smallest): " << pq.top() << endl;

    cout << "All elements (smallest to largest): ";

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
