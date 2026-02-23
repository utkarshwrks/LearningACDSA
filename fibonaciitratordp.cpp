#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }
    if(n == 1){
        cout << 1;
        return 0;
    }

    int a = 0; // F(0)
    int b = 1; // F(1)
    int c;

    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    cout << c;
}
