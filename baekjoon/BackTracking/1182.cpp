/** 백트래킹, 부분수열의 합 */
#include<bits/stdc++.h>
using namespace std;
int N, S, cnt = 0;
int arr[21];

void dfs(int x, int sum) {
    if(x == N) return;
    if(sum+arr[x] == S) cnt++;

    dfs(x+1, sum);
    dfs(x+1, sum + arr[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];
    dfs(0, 0);
    cout << cnt << '\n';
}