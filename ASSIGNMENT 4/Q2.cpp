#include <iostream>
using namespace std;

int front = -1, rear = -1, size;
int arr[100];

bool isempty() {
    return front == -1;
}

bool isfull() {
    return (front == 0 && rear == size - 1) || (rear + 1 == front);
}

void enqueue(int item) {
    if (isfull()) {
        cout << "queue is full" << endl;
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = item;
    }
}

void dequeue() {
    if (isempty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void peek() {
    if (isempty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "front element: " << arr[front] << endl;
    }
}

void display() {
    if (isempty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            if (i == size - 1) {
                i = 0;
            } else {
                i++;
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "enter queue size";
    cin >> size;
    int choice, item;
    while (true) {
        cout << "1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\nenter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter element: ";
            cin >> item;
            enqueue(item);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            break;
        } else {
            cout << "invalid choice" << endl;
        }
    }
    return 0;
}
