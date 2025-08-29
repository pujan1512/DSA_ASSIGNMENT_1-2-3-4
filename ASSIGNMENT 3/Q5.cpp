#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() {
         top = -1; 
        }
    void push(int x) {
         arr[++top] = x;
         }
    int pop() { 
        return arr[top--]; 
    }
    int peek() {
         return arr[top];
         }
    bool isEmpty() { 
        return top == -1;
     }
};

int main() {
    string postfix;
    cout << "enter postfix";
    cin >> postfix;

    Stack s;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];{
        if (isdigit(ch)) {
            s.push(ch - '0');
        
        } 
        else {
            int b = s.pop();
            int a = s.pop();
            if (ch == '+') {
                s.push(a + b);
            }
            else if (ch == '-') {
                s.push(a - b);
            }
            else if (ch == '*') {
                s.push(a * b);
            }
            else if (ch == '/') {
                s.push(a / b);
            }
        }
    }

    cout << "result" << s.peek() << endl;
    return 0;
}
}