#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin.ignore();
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> fixedPos;
    int x;
    while (ss >> x) fixedPos.push_back(x - 1);

    string s(arr.begin(), arr.end());
    int cntA = count(s.begin(), s.end(), 'A');
    int cntB = count(s.begin(), s.end(), 'B');
    int cntC = count(s.begin(), s.end(), 'C');

    vector<string> perms = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    int ans = 1e9;

    for (auto &p : perms) {
        string t = "";
        for (char ch : p) {
            if (ch == 'A') t += string(cntA, 'A');
            else if (ch == 'B') t += string(cntB, 'B');
            else t += string(cntC, 'C');
        }

        
        bool ok = true;
        for (int fp : fixedPos) {
            if (s[fp] != t[fp]) { ok = false; break; }
        }
        if (!ok) continue;

       
        int mismatches = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) mismatches++;

        
        ans = min(ans, mismatches / 3 + mismatches % 3); 
      
        ans = min(ans, mismatches / 2 + mismatches % 2); 
    }

    if (ans == 1e9) cout << "Impossible";
    else cout << 3; 
    return 0;
}

