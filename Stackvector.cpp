#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (!v.empty()) {
            v.pop_back();
        }
    }

    int top() {
        if (!v.empty()) {
            return v[v.size() - 1];
        }
        return -1; // stack empty case
    }

    bool empty() {
        return v.size() == 0;
    }
};

int main() {

    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    if (!s1.empty()) {
        cout << s1.top() << endl;  // 30
        s1.pop();
    }

    if (!s1.empty()) {
        cout << s1.top() << endl;  // 20
    }
}
