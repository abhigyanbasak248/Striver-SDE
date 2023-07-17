#include <bits/stdc++.h>
using namespace std;

//iterative
void selectionSort1(int arr[],int n) {
    for (int i=0;i<n;i++) {
        int min=i;
        for (int j=i;j<n;j++) {
            if (arr[j]<arr[min]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}

//recursive
void selectionSort2(int arr[], int m, int r, int c) {
    if (r == 0) return;
    if (c < r) {
        if (arr[c] > arr[m]) {
            selectionSort2(arr, c, r, c + 1);
        }
        else {
            selectionSort2(arr, m, r, c + 1);
        }
    }
    else {
        swap(arr[m], arr[r - 1]);
        selectionSort2(arr,  0, r - 1, 0);
    }
}

int main() {
    int arr[]={3,4,2,1};
    selectionSort2(arr,0,4,0);
    for (int i=0;i<4;i++) cout<<arr[i]<<' ';
}