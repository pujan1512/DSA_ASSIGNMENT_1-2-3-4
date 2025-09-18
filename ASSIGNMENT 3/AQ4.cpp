#include <iostream>
using namespace std;

int temperatures[100];
int stackIndex[100];
int answer[100];
int top = -1;

void push(int idx) {
    stackIndex[++top] = idx;
}

int pop() {
    return stackIndex[top--];
}

int peek() {
    return stackIndex[top];
}

bool isEmpty() {
    return top == -1;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
        answer[i] = 0; 
    }

    for (int i = 0; i < n; i++) {
        while (!isEmpty() && temperatures[i] > temperatures[peek()]) {
            int prevIndex = pop();
            answer[prevIndex] = i - prevIndex;
        }
        push(i);
    }

    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
