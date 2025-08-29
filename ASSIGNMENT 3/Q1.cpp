#include <bits/stdc++.h>
using namespace std;

class Stack
{
    static const int max = 5;
    int arr[max];
    int top = -1;

public:

    void push(int num)
    {
        if(top == max - 1){
            cout << "stack full";
        }
        else{
            top++;
            arr[top]=num;
        }            
    }

    void pop()
    {
        int popped;
        if (top == -1){
            cout << "not possible,stack is empty";
        }
        else
        {
            popped = arr[top];
            top--;
            cout << "the number popped out is" << popped;
        }
    }
    
    int peek()
    {
        if (top == -1){
            cout << "not possible,stack is empty";
        }
        int above = arr[top];
        return above;
    }

    void isEmpty()
    {
        if (top == -1){
            cout << "stack is empty";
        }
        else{
            cout << "stack is not empty";
        }
    }
    
    void isFull()
    {
        if (top == max-1){
            cout << "stack full";
        }
        else{
            cout << "stack not full";
        }
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Stack s;
    int choice, value;
    while(choice!=7)
    {
        cout << "MENU";
        cout << "1. push\n2. pop\n3. peek\n4. check if empty\n5. check if full\n6. display\n7. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter a number";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 6:
            s.display();
            break;
        default:
            cout << "invalid choice";
        }
    }
    cout << "exiting program";
    return 0;
}