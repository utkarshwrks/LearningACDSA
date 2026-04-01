#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

class Solution {
public:

    void traverse(Node* root, string str, vector<string> &ans) {
        if (!root) return;

        // Leaf node
        if (!root->left && !root->right) {
            ans.push_back(str);
            return;
        }

        traverse(root->left, str + "0", ans);
        traverse(root->right, str + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Create leaf nodes
        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i]));
        }

        // Build Huffman Tree
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        Node* root = pq.top();

        vector<string> ans;
        traverse(root, "", ans);

        return ans;
    }
};