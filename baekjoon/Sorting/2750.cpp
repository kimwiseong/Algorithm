/** 삽입, 선택, 거품정렬 O(n^2) */
#include<bits/stdc++.h>
using namespace std;
int n, arr[1100];

//삽입정렬
void insertionSort() {
    int key;
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j >= 0 && arr[j] > arr[j + 1]; j--) {
            key = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = key;
        }
    }
}

//거품정렬
void bubbleSort() {
    int key;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n-1; j++) 
            if(arr[j] > arr[j+1]) {
                // key = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = key;
                swap(arr[j], arr[j+1]);
            }
}

//선택정렬
void selectionSort() {
    int key, min, idx;
    for (int i = 0; i < n; i++) {
        min = 10000;
        for (int j = i; j < n; j++) {
            if(min > arr[j]) {
                idx = j;
                min = arr[j];
            }
        }
        key = arr[i];
        arr[i] = arr[idx];
        arr[idx] = key;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    bubbleSort(); 
    // insertionSort();
    // selectionSort();
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}