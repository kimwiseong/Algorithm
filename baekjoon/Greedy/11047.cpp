/** greedy, 동전 최소 갯수 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, a[10], cnt = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = n - 1; i >= 0; i--) {
        cnt += (k/a[i]);
        k %= a[i];
    }
    cout << cnt << '\n';
}