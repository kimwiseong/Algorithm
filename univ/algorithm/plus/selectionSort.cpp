#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t; 
}

void selectionSort(int a[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = minIndex+1; j < n; j++) 
            if(a[minIndex] > a[j]) 
                minIndex = j;
            
        if (minIndex != i) 
            swap(a, i, minIndex);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;
    
    selectionSort(a, n);
    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';
    delete[] a;
}