#include <iostream>
using namespace std;

int stackArr[100];
int top = -1;
int minElement;

void push(int x) {
    if (top == -1) {
        top++;
        stackArr[top] = x;
        minElement = x;
    } 
    else if (x >= minElement) {
        top++;
        stackArr[top] = x;
    } 
    else {
        top++;
        stackArr[top] = 2 * x - minElement; 
        minElement = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    int t = stackArr[top];
    top--;
    if (t < minElement) {
        minElement = 2 * minElement - t;
    }
}

int peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return -1;
    }
    if (stackArr[top] >= minElement)
        return stackArr[top];
    else
        return minElement;
}

int getMin() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minElement;
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);
    push(8);

    cout << "Current Min: " << getMin() << "\n"; 
    pop();
    cout << "Current Min: " << getMin() << "\n"; 
    pop();
    cout << "Current Min: " << getMin() << "\n"; 
    pop();
    cout << "Top Element: " << peek() << "\n"; 
    cout << "Current Min: " << getMin() << "\n";

    return 0;
}
