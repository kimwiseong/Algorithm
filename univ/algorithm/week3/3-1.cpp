#include <iostream>
#include <ctime>
#include <cstdlib>
#define itemType int
using namespace std;

int swapCount, compCount;

void insertion(itemType a[], int N) {
    int i, j; itemType v;
    for (i = 1; i < N; i++) {
        v = a[i];
        j = i-1;
        compCount++;
        while (j >= 0 && v < a[j]) {
            swapCount++;
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

int main() {
    srand(time(NULL));
    int n;
    cin >> n;

    itemType *a = new int[n];
    itemType *b = new int[n];
    itemType *c = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;             // best 
        b[i] = n-i;           // worst
        c[i] = rand() % 1000; // random
    }

    insertion(a, n);
    cout << "best case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수" << swapCount << "\n\n"; 
    swapCount = 0; compCount = 0;

    insertion(b, n);
    cout << "worst case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수" << swapCount << "\n\n"; 
    swapCount = 0; compCount = 0;

    insertion(c, n);
    cout << "random case\n비교 연산횟수 : " << compCount << "\n자료이동 연산회수" << swapCount << "\n\n"; 

    delete[] a;
    delete[] b;
    delete[] c;
}