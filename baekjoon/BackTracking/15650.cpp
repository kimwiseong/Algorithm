/** dfs, backtracking */
#include <bits/stdc++.h>
using namespace std;
int N, M;
bool used[9];
int num[9];

void dfs(int x, int pre) {
    if (x == M) {
        for (int i = 0; i < M; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = pre + 1; i <= N; i++) {
        if (used[i]) continue;
        used[i] = true;
        num[x] = i;
        dfs(x + 1, i);
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    dfs(0, 0);
}