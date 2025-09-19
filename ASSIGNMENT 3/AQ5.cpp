#include <bits/stdc++.h>
using namespace std;
#define n 100
class Stack{
	int arr[n];
	int top=-1;
public:
	void push(int num){
		if(top==n-1){
			cout<<"Stack Full\n";
			return;
		}
		arr[++top]=num;
	}
	int pop(){
		if(top==-1){
			cout<<"Stack Empty\n";
			return -1;
		}
		return arr[top--];
	}
	int peek(){
		if(top==-1) return -1;
		return arr[top];
	}
	int isEmpty(){
		return (top==-1);
	}
};
void ss(){
    Stack s;
    int count=0;
    int size;
    cout<<"Enter sizze: ";
    cin>>size;
    int a[]={3,1,2,4},b[size];
    for(int i=1;i<=size;i++){
	    s.push(i);	
	    while(!s.isEmpty()&&s.peek()==a[count]){
		    s.pop();
		    count++;
	}
}
    if(s.isEmpty()) cout<<"YES";
    else cout<<"NO";
}
int main(){
	ss();
	return 0;
}