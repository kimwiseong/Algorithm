// 세크먼트 트리, 요세푸스 문제
#include <iostream>
using namespace std;

int tree[400000];

int init(int v, int s, int e) {
    if (s == e) return tree[v] = 1;
    return tree[v] = init(2 * v, s, (s+e)/2) + init(2 * v + 1, (s+e)/2 + 1, e);
}

int findNum(int v, int s, int e, int k) {
    tree[v]--;
    if (s == e) return s;
    if (tree[2 * v] >= k) return findNum(2 * v, s, (s+e)/2, k);
    else return findNum(2 * v + 1, (s+e)/2 + 1, e, k - tree[2 * v]);
}

int main () {
    int n, k;
    cin >> n >> k;
    init(1, 1, n);
    int x = k;

    cout << '<';
    for (int i = 0; i < n - 1; i++) {
        cout<< findNum(1, 1, n, x) << ", ";
        x += k - 1;
        if (x % tree[1] == 0) x = tree[1];
        else x %= tree[1]; 
    }
    cout << findNum(1, 1, n, x) << "> \n";
}