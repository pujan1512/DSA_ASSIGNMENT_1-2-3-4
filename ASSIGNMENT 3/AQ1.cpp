#include <iostream>
using namespace std;

int n;
int arr[100];
int stackArr[100];
int top = -1;

void push(int val) {
    stackArr[++top] = val;
}
void pop() {
    top--;
}
int peek() {
    return stackArr[top];
}
bool isEmpty() {
    return top == -1;
}

int main() {
    cout << "enter size of array:";
    cin >> n;

    cout << "enter array elements:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int need = 1, i = 0;

    while (i < n || !isEmpty()) {
        if (!isEmpty() && peek() == need) {
            pop();
            need++;
        } 
        else if (i < n) {
            push(arr[i]);
            i++;
        } 
        else {
            break;
        }
    }

    if (need == n + 1) cout << "YES";
    else cout << "NO";

    return 0;
}
