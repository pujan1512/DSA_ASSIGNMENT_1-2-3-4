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

bool isBalanced(string expr) {
    Stack s;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "enter an expression";
    cin >> expr;
    if (isBalanced(expr)){
        cout << "expression is balanced";
    }
    else{
        cout << "expression is not balanced";
    }
    return 0;
}