#include <iostream>
#include <ctime>
using namespace std;

void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t; 
}

int partition(int b[], int l, int r) {
    int i, j; int v;
    if (r > l) {
        v = b[l]; i = l; j = r + 1;
        while (true) {
            while(b[++i] < v && i < r);
            while(b[--j] > v && j > l);
            if (i >= j) break;
            swap(b, i, j);
        }
        swap(b, j, l);
    }
    return j;
}

void quickSort(int b[], int l, int r) {
    int j;
    if(r > l) {
        j = partition(b, l, r);
        quickSort(b, l, j-1);
        quickSort(b, j+1, r);
    }
}


int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];

    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;

    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    delete[] a;
}
