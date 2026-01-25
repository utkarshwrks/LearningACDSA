#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Stack {
    list<int>l;
public:
    void push(int val) {
        l.push_front(val);
    }

    void pop() {
        l.pop_front();
    }

    int top() {
        
            if (!l.empty()) {
            return l.front();
        }
        return -1;
        
    }

    bool empty() {
        return l.size() == 0;
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
