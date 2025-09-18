#include <iostream>
using namespace std;

int n;
int arr[100];
int stackArr[100];
int top = -1;

void push(int val) {
    stackArr[++top] = val;
}

int pop() {
    return stackArr[top--];
}

int peek() {
    return stackArr[top];
}

bool isEmpty() {
    return top == -1;
}

int main() {
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Nearest Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        while (top != -1 && stackArr[top] >= arr[i]) {
            pop();
        }

        if (isEmpty()) {
            cout << "-1 ";
        } else {
            cout << peek() << " ";
        }

        push(arr[i]);
    }

    return 0;
}
