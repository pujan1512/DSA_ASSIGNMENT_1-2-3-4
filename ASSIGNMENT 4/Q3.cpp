#include <iostream>
using namespace std;

void interleave(int arr[], int n) {
    int half = n/2;
    cout << "interleaved queue: ";
    for (int i=0; i<half; i++) {
        cout << arr[i] << " " << arr[i + half] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int arr[100];
    cout << "enter number of elements: ";
    cin >> n;
    cout << "enter elements: ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    interleave(arr, n);
    return 0;
}
