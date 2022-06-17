/** DP, 순열 */
#include<bits/stdc++.h>
using namespace std;

int n, cnt, DP[1000], arr[1000];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
            DP[i] = arr[i] > arr[j] ? max(DP[i], DP[j]+1) : DP[i];
        cnt = max(DP[i], cnt);
    }

    cout << cnt << '\n';
}
