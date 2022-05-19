/** backtracking, dfs, N과 M(11) */
#include<bits/stdc++.h>
using namespace std;
int N, M, num[10], arr[10];

void dfs(int x) {
    if(x == M) {
        for (int i =0; i < M; i++) 
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    int overlap = 0;
    for (int i = 0; i < N; i++) {
        if(overlap == arr[i]) continue;
        overlap = arr[i];
        num[x] = arr[i];
        dfs(x+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
    sort(arr, arr+N);
    dfs(0);
}