#include <bits/stdc++.h>
using namespace std;

//iterative
void bubbleSort1(int arr[],int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

//recursive
void bubbleSort2(int arr[], int r, int c) {
    if (r == 0) return;
    if (c < r) {
        if (arr[c] > arr[c + 1]) swap(arr[c], arr[c + 1]);
        bubbleSort2(arr, r, c + 1);
    }
    else {
        bubbleSort2(arr, r - 1, 0);
    }
}

int main() {
    int arr[]={4,3,5,1,2};
    bubbleSort2(arr, 4, 0);
    for (int i=0;i<5;i++) cout<<arr[i]<<' ';
}