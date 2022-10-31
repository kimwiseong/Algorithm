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

int partition(itemType a[], int l, int r) {
    int i, j; itemType v;
    if (r > l) {
        v = a[l]; i = l; j = r + 1;
        while (true) {
            while(a[++i] < v && i < r) compCount++;
            while(a[--j] > v && j > l) compCount++;
            compCount++;
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, j, l);
    }
    return j;
}


void quicksort(itemType a[], int l, int r) {
    int j;
    compCount++;
    if (r > l) {
        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int main() {
    srand(time(NULL));
    int n;
    cin >> n;

    itemType *a = new int[n];
    itemType *b = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;               //worst case 
        b[i] = rand() % 1000;   //random case

    }

    quicksort(a, 0, n-1);
    cout << "worst case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수 : " << swapCount << "\n\n";
    swapCount = 0; compCount = 0;
    quicksort(b, 0, n-1);
    cout << "random case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수 : " << swapCount << "\n\n";
    
    delete[] a;
    delete[] b;
}