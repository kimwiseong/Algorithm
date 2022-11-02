#include <iostream>
#include <ctime>
#include <cstdlib>
#define itemType int
using namespace std;

unsigned long int total;

void swap(itemType arr[], int i, int j) {
    itemType t = arr[i]; arr[i] = arr[j]; arr[j] = t; 
    total += arr[i] < arr[j] ? arr[i] * 2 + arr[j] : arr[j] * 2 + arr[i];
}

void insertion(itemType a[], int N) {
    int i, j, temp; itemType v;
    
    for (i = 1; i < N; i++) {
        v = a[i];
        j = i;
        temp = 0;
        bool flag = false;
        while (j >= 0 && v < a[j-1]) {
            flag = true;
            temp += a[j-1];
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
        if (flag)
            total += v*2 + temp;
    }
}

//quick
int partition(itemType b[], int l, int r) {
    int i, j; itemType v;
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

void quicksort(itemType b[], int l, int r) {
    int j;
    if(r > l) {
        j = partition(b, l, r);
        quicksort(b, l, j-1);
        quicksort(b, j+1, r);
    }
}

//heap
void MakeHeap(int c[ ], int root, int lastNode) {      
    int  parent, left, right, son, rootValue;
    
    parent = root;
    rootValue = c[root];
    left = 2 * parent + 1;
    right = left + 1;

    while (left <= lastNode)  {
        if (right <= lastNode && c[left] < c[right])
            son = right;
        else  son = left;

        if (rootValue < c[son])  {
            total += c[parent] < c[son] ? c[parent] * 2 + c[son] : c[son] * 2 + c[parent];
            c[parent] = c[son];
            parent = son;
            left = parent * 2 + 1;
            right = left + 1;   
        }
        else break; 
    }
    c[parent] = rootValue; 
}

void HeapSort(itemType c[], int n) {
    int i;
    for (i = n/2; i > 0; i--) 
        MakeHeap(c, i-1, n-1);
    
    for (i = n-1; i > 0; i--) {
        swap(c, 0, i);
        MakeHeap(c, 0, i-1);
    }
}


int main() {
    srand(time(NULL));
    int n;
    cin >> n;

    itemType *a = new int[n];
    itemType *b = new int[n];
    itemType *c = new int[n];
    for (int i = 0; i < n; i++) 
        a[i] = b[i] = c[i] = rand() % 1000;
    
    insertion(a, n);
    cout << "insertion sort, 이동한 물건의 무게의 합 : " << total << '\n';
    total = 0;
    quicksort(b, 0, n-1);
    cout << "quick sort, 이동한 물건의 무게의 합 : " << total << '\n';
    total = 0;
    HeapSort(c, n);
    cout << "heap sort, 이동한 물건의 무게의 합 : " << total << '\n';
}