#include <iostream>
using namespace std;

int arr[100];
int stackArr[100];
int result[100];
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
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && peek() <= arr[i]) {
            pop();
        }

        if (isEmpty()) {
            result[i] = -1;
        } else {
            result[i] = peek();
        }

        push(arr[i]);
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
