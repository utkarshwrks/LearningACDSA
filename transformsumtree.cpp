#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build tree using preorder with -1 as NULL
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Preorder traversal (Root Left Right)
void preorderPrint(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// Convert tree to Sum Tree
int sumTree(Node* root) {
    if (root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    idx = -1; // reset index
    Node* root = buildTree(preorder);

    cout << "Preorder before sumTree: ";
    preorderPrint(root);
    cout << endl;

    sumTree(root);

    cout << "Preorder after sumTree: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}
