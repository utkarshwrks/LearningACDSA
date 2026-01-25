#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);

        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue khali hai\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    int front() {
        if (empty()) {
            cout << "Queue khali hai\n";
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10

    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 20

    q.pop();
    q.pop();

    q.pop(); // Queue khali hai

    return 0;
}
