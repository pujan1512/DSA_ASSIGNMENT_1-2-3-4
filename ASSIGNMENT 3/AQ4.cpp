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
void dailyTemperatures(int temp[],int size,int ans[]){
	Stack s;
	for(int i=0;i<size;i++){
		while(!s.isEmpty()&&temp[i]>temp[s.peek()]){
			int prev=s.pop();
			ans[prev]=i-prev;
		}
		s.push(i);
	}
}
int main(){
	int temp[]={7,6,3,3,53,5,30};
	int size=sizeof(temp)/sizeof(temp[0]);
	int ans[n]={0};
	dailyTemperatures(temp,size,ans);
	for(int i=0;i<size;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
