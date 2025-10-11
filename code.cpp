#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter character: ";
    cin >> ch;

    if (ch >= 65 && ch <= 90) {
        cout << "Character is capital";
    } 
    else if (ch >= 97 && ch <= 122) {
        cout << "Character is small";
    } 
    else {
        cout << "Special character";
    }
}
