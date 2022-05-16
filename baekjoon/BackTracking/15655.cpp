/** dfs, backtracking, N과 M(6) */ 
#include<bits/stdc++.h>
using namespace std;

int N, M, num[10], arr[10];
bool used[10];

void dfs(int x, int pre) {
    if(x == M) {
        for (int i = 0; i < M; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = pre; i < N; i++) {
        if(used[i]) continue;
        used[i] = true;
        num[x] = arr[i];
        dfs(x+1, i);
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    dfs(0, 0);
}