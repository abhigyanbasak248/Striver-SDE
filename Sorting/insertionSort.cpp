#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n) {
    for (int i=1;i<n;i++) {
        int j=i;
        while (j>=0 && arr[j]<arr[j-1]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}


int main() {
    int arr[]={5,6,7,1,7};
    insertionSort(arr,5);
    for (int i=0;i<5;i++) cout<<arr[i]<<' ';
}
