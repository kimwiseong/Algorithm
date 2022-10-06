#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int a[], int i, int j) { 
    int t = a[i]; a[i] = a[j]; a[j] = t; 
}

void bubbleSort(int a[], int n) {
    int i;
    bool sorted = false;

    while(!sorted) {
        sorted = true;
        for (i = 1; i < n; i++)
            if (a[i-1] > a[i]) {
                swap(a, i, i-1);
                sorted = false;
            }
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;
    
    bubbleSort(a, n);
    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';
    delete[] a;
}