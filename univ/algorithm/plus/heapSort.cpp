#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t; 
}

void MakeHeap(int a[ ], int root, int lastNode) {      
    int  parent, left, right, son, rootValue;
    
    parent = root;
    rootValue = a[root];
    left = 2 * parent + 1;
    right = left + 1;

    while (left <= lastNode)  {
        if (right <= lastNode && a[left] < a[right])
            son = right;
        else  son = left;

        if (rootValue < a[son])  {
            a[parent] = a[son];
            parent = son;
            left = parent * 2 + 1;
            right = left + 1;   
        }
        else break; 
    }

    a[parent] = rootValue; 
}

void HeapSort(int a[], int n) {
    int i;
    for (i = n/2; i > 0; i--) 
        MakeHeap(a, i-1, n-1);
    
    for (i = n-1; i > 0; i--) {
        swap(a, 0, i);
        MakeHeap(a, 0, i-1);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];

    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;
    
    HeapSort(a, n);
    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';

    delete[] a;
}