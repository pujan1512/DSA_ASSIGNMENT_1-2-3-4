#include <iostream>
using namespace std;

void concatenateStrings(char str1[], char str2[]) {
    int i = 0, j = 0;
    
    while (str1[i] != '\0') {
        i++;
    }

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

int main() {
    char str1[100], str2[100];

    cout << "enter first string: ";
    cin >> str1;
    cout << "enter second string: ";
    cin >> str2;

    concatenateStrings(str1, str2);

    cout << "concatenated string: " << str1 << endl;

    return 0;
}
