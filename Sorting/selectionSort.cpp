#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n) {
    for (int i=0;i<n;i++) {
        int min=i;
        for (int j=i;j<n;j++) {
            if (arr[j]<arr[min]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}

int main() {
    int arr[]={3,4,2,1};
    selectionSort(arr,4);
    for (int i=0;i<4;i++) cout<<arr[i]<<' ';
}