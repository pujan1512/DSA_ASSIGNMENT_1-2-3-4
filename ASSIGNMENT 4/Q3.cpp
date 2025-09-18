#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }
    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) { if (!isFull()) arr[++top] = x; }
    int pop() { return isEmpty() ? -1 : arr[top--]; }
};

int main() {
    Queue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    int half = q.size() / 2;
    Stack s;
    for (int i = 0; i < half; i++)
        s.push(q.dequeue());
    while (!s.isEmpty())
        q.enqueue(s.pop());
    for (int i = 0; i < half; i++)
        q.enqueue(q.dequeue());
    for (int i = 0; i < half; i++)
        s.push(q.dequeue());
    while (!s.isEmpty()) {
        q.enqueue(s.pop());
        q.enqueue(q.dequeue());
    }
    q.display();
    
    return 0;
}