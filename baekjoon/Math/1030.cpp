/** 프렉탈 평면 */
#include<bits/stdc++.h>
using namespace std;
int s, n, k, r1, r2, c1, c2;

int solve(int i, int j, int N) {
    if(N == 1) return 0;
    int temp = N/n;
    if (i >= (temp*(n-k)) / 2 && i < (temp*(n+k))/2 && j >= (temp*(n-k))/2 && j < (temp*(n+k))/2)
        return 1;
    return solve (i % temp, j % temp, temp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    int N = pow(n, s);
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++)
            cout << solve(i, j, N);
        cout << '\n';
    }
    return 0;
}