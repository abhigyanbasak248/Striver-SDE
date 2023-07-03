#include <bits/stdc++.h>
using namespace std;

// int secondLargest(int arr[],int n) {
//     int max=arr[0];
//     int sec_max=-1;
//     for (int i=1;i<n;i++) {
//         if (arr[i]>max) {
//             sec_max=max;
//             max=arr[i];

//         }
//         else if (arr[i]<max && arr[i]>sec_max) {
//             sec_max=arr[i];
//         }
//     }
//     return sec_max;
// }

int main() {
    int arr[]={4,6,7,7,5};
    cout<<secondLargest(arr,5);
}