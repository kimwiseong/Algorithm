#include <iostream>
using namespace std;

int arr[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, i, j;
    cin >> n >> m;
    for (int k = 1; k <= n; k++){
        cin >> arr[k];
        arr[k] += arr[k-1];
    }

    while(m--) {
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }
}