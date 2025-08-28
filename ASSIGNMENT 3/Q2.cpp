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
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string word;
    cout << "enter a word";
    cin >> word;

    Stack s;
    for (int i = 0; i < word.length(); i++) {
        s.push(word[i]);
    }

    cout << "reversed word";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}