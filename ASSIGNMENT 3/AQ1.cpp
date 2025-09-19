#include <bits/stdc++.h>
using namespace std;
void nse(){
    int n,m=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n],ans[n];
    cout<<"Enter array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            cout<<-1<<" ";
        }
        else{
            for(int j=i-1;j>=0;j--){
                m=0;
                if(arr[j]<arr[i]){
                    cout<<arr[j]<<" ";
                    m=1;
                    break;
                }
            }
            if(m==0) cout<<-1<<" ";
        }
    }
}
int main(){
    nse();
    return 0;
}
