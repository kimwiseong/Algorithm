#include <iostream>
#include <ctime>
using namespace std;

void merge(int *list, int left, int mid, int right, int size) {
    int i = left, j = mid+1, k = left, l;
    int *tmp = new int[size]; 

    while (i<=mid && j<=right) {
        if (list[i] < list[j]) tmp[k++] = list[i++];
        else  tmp[k++] = list[j++];
    }

    if (i>mid) 
        for (l=j; l<=right; l++)
            tmp[k++] = list[l];
    
    else 
        for (l=i; l<=mid; l++)
            tmp[k++] = list[l];
    
    for (l=left; l<=right; l++) 
        list[l] = tmp[l];
    
    delete[] tmp;
}

void mergeSort(int *list, int left, int right, int size) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(list, left, mid, size);
        mergeSort(list, mid+1, right, size);
        merge(list, left, mid, right, size);
    }
}


int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];

    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;

    mergeSort(a, 0, n-1, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    delete[] a;
}
