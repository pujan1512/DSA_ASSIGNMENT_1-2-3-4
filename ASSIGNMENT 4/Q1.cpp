#include <iostream>
using namespace std;

int front = -1, rear = -1, size;
int arr[100];

bool isEmpty(){
    return front == -1;
}

bool isFull(){
    return rear == size - 1;
}

void enqueue(int i){
    if (isFull()) {
        cout << "queue is full" << endl;
    }
    else{
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = i;
    }
}

void dequeue(){
    if (isEmpty()){
        cout << "queue is empty" << endl;
    }
    else{
        cout << "dequeue" << arr[front] << endl;
        if (front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
    }
}
void peek()
{
    if (isEmpty()){
        cout << "Queue is Empty" << endl;
    }
    else{
        cout << "Front Element: " << arr[front] << endl;
}
}
void display()
{
    if (isEmpty()){
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        cout << endl;
        }
    }
}
int main()
{
    cout << "enter size";
    cin >> size;
    int choice, item;
    while (true)
    {
        cout << "1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\nenter choice";
        cin >> choice;
        if (choice == 1) {
            cout << "enter elements: ";
            cin >> item;
            enqueue(item);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            peek();
        else if (choice == 4)
            display();
        else if (choice == 5)
            break;
        else
            cout << "invalid Choice" << endl;
    }
    return 0;
}