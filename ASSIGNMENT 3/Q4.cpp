#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;
public:
    Stack() {
         top = -1;
        }
    void push(char c) {
         arr[++top] = c; 
        }
    char pop() {
         return arr[top--];
         }
    char peek() {
         return arr[top];
         }
    bool isEmpty() { 
        return top == -1; 
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int main() {
    string infix, postfix = "";
    cout << "Enter infix: ";
    cin >> infix;
    Stack s;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            s.push(ch);
        } 
        else if (ch == ')') {
            while (!s.isEmpty()) {
        postfix += s.pop();
    }

    cout << "postfix" << postfix << endl;
    return 0;
        }
    }
}
