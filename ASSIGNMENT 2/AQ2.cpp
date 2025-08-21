#include <iostream>
using namespace std;

bool canSplitIntoThree(string s) {
    int n = s.length();
    for (int len = 1; len < n; len++) {
        string part = s.substr(0, len);
        string rest = s.substr(len);
        if (rest.find(part) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cout << "enter string: ";
    cin >> s;

    if (canSplitIntoThree(s)) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
