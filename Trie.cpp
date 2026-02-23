#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {

        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {

        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if(root->children[index] == NULL) {
            return false;
        }

        return searchUtil(root->children[index], word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // -------- REMOVE SECTION --------

    bool isEmpty(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL)
                return false;
        }
        return true;
    }

    TrieNode* removeUtil(TrieNode* node, string word) {

        if(node == NULL)
            return NULL;

        // base case
        if(word.length() == 0) {

            if(node->isTerminal)
                node->isTerminal = false;

            if(isEmpty(node)) {
                delete node;
                node = NULL;
            }

            return node;
        }

        int index = word[0] - 'A';

        node->children[index] =
            removeUtil(node->children[index], word.substr(1));

        if(node->children[index] == NULL &&
           node->isTerminal == false &&
           isEmpty(node)) {

            delete node;
            node = NULL;
        }

        return node;
    }

    void removeWord(string word) {
        root = removeUtil(root, word);
    }
};

int main() {

    Trie t;

    t.insertWord("HELLO");
    t.insertWord("HELL");
    t.insertWord("WORLD");

    cout << "Before delete:\n";
    cout << "HELLO: " << t.searchWord("HELLO") << endl;
    cout << "HELL: " << t.searchWord("HELL") << endl;

    t.removeWord("HELLO");

    cout << "\nAfter delete HELLO:\n";
    cout << "HELLO: " << t.searchWord("HELLO") << endl;
    cout << "HELL: " << t.searchWord("HELL") << endl;

    return 0;
}
