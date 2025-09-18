#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    char arr[MAX];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }
    void enqueue(char x) {
        if (rear < MAX - 1) {
            if (front == -1)
                front = 0;
            arr[++rear] = x;
        }
    }
    char dequeue() {
        if (isEmpty())
            return '\0';
        char val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return val;
    }
    char peek() {
        return isEmpty() ? '\0' : arr[front];
    }
};

int main() {
    Queue q;
    int count[256] = {0};
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch != ' ') {
            q.enqueue(ch);
            count[ch]++;
        }
    }
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch != ' ') {
            if (count[ch] == 1)
                cout << ch << " ";
            else
                cout << "-1" << " ";
            count[ch]--;
        }
    }

    return 0;
}