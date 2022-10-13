#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int n = 10;

void insertionSort(int a[], int N) {
    int i, j, temp; int v;
    
    for (i = 1; i < N; i++) {
        v = a[i];
        j = i;
        while (j >= 0 && v < a[j-1]) {
            temp += a[j-1];
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;
    
    insertionSort(a, n);
    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';
    delete[] a;
}