#include <bits/stdc++.h>
using namespace std;

void leftRotate1(int arr[], int n, int d) {
 int k=d%n;
	int temp[k];
	for (int i=0;i<k;i++) temp[i]=arr[i];
	for (int i=k;i<n;i++) arr[i-k]=arr[i];
	for (int i=n-k;i<n;i++) arr[i]=temp[i-n+k];
}

void leftRotate2(int arr[], int n, int d) {
    int k=d%n;
	int temp[k];
    for (int i=0;i<k;i++) temp[i]=arr[i];
	for (int i=k;i<n;i++) arr[i-k]=arr[i];
	for (int i=n-k;i<n;i++) arr[i]=temp[i-n+k];
}
