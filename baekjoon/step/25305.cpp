//merge sort
#include <iostream>
#include <ctime>
using namespace std;

int n, k;

void merge(int *list, int left, int mid, int right) {
    int i = left, j = mid+1, k = left, l;
    int tmp[1000];

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
}

void mergeSort(int *list, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    int a[1000];
    cin >> n >> k;

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    mergeSort(a, 0, n-1);

    cout << a[n-k] << '\n';
}

