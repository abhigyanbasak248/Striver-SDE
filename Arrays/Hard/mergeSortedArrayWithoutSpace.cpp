#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int len = m + n;
            int gap = (len/2) + (len%2);
            while (gap > 0) {
                int left = 0;
                int right = left + gap;
                while(right < len) {
                    //arr1 and arr2
                    if (left < n && right >= n) {
                        if (arr1[left] > arr2[right-n]) {
                            swap(arr1[left], arr2[right-n]);
                        }
                    }
                    //arr1 and arr1
                    else if (left >= n){
                        if (arr2[left-n] > arr2[right-n]) {
                            swap(arr2[left-n], arr2[right-n]);
                        }
                    }
                    else {
                        if (arr1[left] > arr1[right]) {
                            swap(arr1[left], arr1[right]);
                        }
                    }
                    //arr2 and arr2
                    
                    left++,right++;
                }
                if (gap == 1) break;
                gap = (gap / 2) + (gap % 2);
            }
        } 