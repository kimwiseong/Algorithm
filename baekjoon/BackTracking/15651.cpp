/** dfs, backtracking */
#include <bits/stdc++.h>
using namespace std;
int N, M;
int num[9];

void dfs(int x) {
    if (x == M) {
        for (int i = 0; i < M; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        num[x] = i;
        dfs(x + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    dfs(0);
}