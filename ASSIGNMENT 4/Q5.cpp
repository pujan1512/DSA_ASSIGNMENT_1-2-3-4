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
        if (!isFull()) {
            if (front == -1) front = 0;
            arr[++rear] = x;
        }
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
    int size() {
        return isEmpty() ? 0 : rear - front + 1;
    }
};

class Stack {
    Queue q;
public:
    void push(int x) {
        int n = q.size();
        q.enqueue(x);
        for (int i = 0; i < n; i++) {
            q.enqueue(q.dequeue());
        }
    }
    int pop() {
        return q.dequeue();
    }
    int top() {
        if (q.isEmpty()) return -1;
        int val = q.dequeue();
        q.enqueue(val);
        return val;
    }
    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl; 
    cout << s.pop() << endl; 
    cout << s.pop() << endl; 
    return 0;
}
