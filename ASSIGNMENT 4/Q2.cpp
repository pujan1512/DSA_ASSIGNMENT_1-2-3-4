#include <iostream>
using namespace std;
#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "overflow";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear+1)%MAX;
        arr[rear] = x;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "underflow";
            return;
        }
        cout << "dequeued: " << arr[front] << endl;
        if(front == rear) {
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "queue is empty";
        }else{
            cout << "front element" << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "queue is empty";
            return;
        }
        cout << "queue";
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i == rear) {
                break;
            }
            i = (i+1)%MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;
    while (true) {
        cout << "1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                return 0;
            default:
                cout << "invalid choice";
        }
    }
}