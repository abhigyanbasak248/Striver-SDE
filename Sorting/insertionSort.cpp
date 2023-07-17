#include <bits/stdc++.h>
using namespace std;

//iterative
void insertionSort1(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j >= 0 && arr[j] < arr[j - 1]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

//recursive
void insertionSort2(int arr[], int n) {
    if (n <= 1) return;
    insertionSort2(arr, n - 1);

    int j = n - 1;
    while (j >= 0 && arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
        j--;
    }
}

int main() {
    int arr[]={5,6,7,1,7};
    insertionSort2(arr, 5);
    for (int i=0;i<5;i++) cout<<arr[i]<<' ';
}
