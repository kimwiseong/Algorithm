#include <iostream>
#include <ctime>
#include <cstdlib>
#define itemType int
using namespace std;

int swapCount, compCount;

void swap(itemType a[], int i, int j) {
    swapCount++;
    itemType t = a[i]; a[i] = a[j]; a[j] = t; 
}

void MakeHeap(int a[ ], int root, int lastNode) {      
    int  parent, left, right, son, rootValue;
    
    parent = root;
    rootValue = a[root];
    left = 2 * parent + 1;
    right = left + 1;

    compCount++;
    while (left <= lastNode)  {
        compCount++;
        if (right <= lastNode && a[left] < a[right])
            son = right;
        else  son = left;

        compCount++;
        if (rootValue < a[son])  {
            swapCount++;
            a[parent] = a[son];
            parent = son;
            left = parent * 2 + 1;
            right = left + 1;   
        }
        else break; 
    }

    a[parent] = rootValue; 
}

void HeapSort(itemType a[], int n) {
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
    int n;
    cin >> n;

    itemType *a = new int[n];
    itemType *b = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000; //random
        b[i] = i;             //이미 정렬된 수
    }

    HeapSort(a, n);
    cout << "random case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수 : " << swapCount << "\n\n"; 
    swapCount = 0; compCount = 0;
    HeapSort(b, n);
    cout << "이미 정렬되었을 경우\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수 : " << swapCount << "\n\n"; 

    delete[] a;
    delete[] b;
}