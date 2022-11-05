#include <iostream>
#include <ctime>
#include <cstdlib>
#define itemType int
using namespace std;

int midCount, mixMaxCount;

void swap(itemType a[], int i, int j) { itemType t = a[i]; a[i] = a[j]; a[j] = t; }

void findMinMax (int a[], int n, int &min, int &max) {
    int i, small, large ;
    min=a[0]; max=a[0];
    for (i = 1; i < n-1 ; i+=2) { 
        mixMaxCount++;
        if (a[i] < a[i+1]) {
            small = a[i]; 
            large = a[i+1];
        } 
        else {
            small = a[i+1]; 
            large = a[i];
        }        
        mixMaxCount++;
        if (small < min) min = small;
        mixMaxCount++;
        if (large > max) max = large;
    }
    return; 
}

int partition(int a[], int l, int r) {
    int partElem, value;
    int i = l, j = r;

    partElem = l;
    value = a[partElem];
    while(true) {
        while(a[++i] < value && i < r) midCount++;
        while(a[--j] > value && j > l) midCount++;
        midCount++;
        if (i < j) swap(a, i, j);
        else break;
    } 
    a[partElem] = a[j];
    a[j] = value;
    return j;
}

itemType select(itemType a[], int n, int k) {
    int j, l = 0, r = n;
    
    midCount++;
    while (r>l) {
        j = partition(a, l, r);
        midCount++;
        if (k == j+1) return a[j];
        else if (k < j+1) r = j;
        else l = j+1;
    }
    return 0;
} 

int main() {
    srand(time(NULL));
    int n, min = 0, max = 0;
    cin >> n;
    itemType *a = new int[n];

    for (int i = 0; i < n; i++) 
        a[i] = rand() % n;
        //a[i] = i; //최악의 경우

    findMinMax(a, n, min, max);
    cout << "최소치 : " << min << ", 최대치 : " << max << ", 최소,최대치 비교회수 : " << mixMaxCount  << '\n';
    cout << "중앙치 : " << select (a, n-1, int(n/2)) << ", 중앙치 비교회수 : " << midCount  << '\n';

    delete[] a;
}