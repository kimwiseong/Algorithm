/** backtracking, dfs, N과 M(9) */
#include<bits/stdc++.h>
using namespace std;
int N, M, num[10], arr[10];
bool used[10];

void dfs(int x) {
    if(x == M) {
        for (int i = 0; i < M; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    
    int overlap = 0; //중복제거
    for (int i = 0; i < N; i++) {
        if(used[i] || arr[i] == overlap) continue;
        overlap = arr[i]; 
        used[i] = true;
        num[x] = arr[i];
        dfs(x+1);
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
    dfs(0);
}