#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main() {
    int arr[]={4,3,5,1,2};
    bubbleSort(arr,5);
    for (int i=0;i<5;i++) cout<<arr[i]<<' ';
}