/** bishop, backtracking */
#include<bits/stdc++.h>
using namespace std;
int n, color, ans[2];
bool board[20][20], diagLeft[40], diagRight[40];

void dfs(int x, int y, int cnt) {
    ans[color] = max(cnt, ans[color]);

    if(x >= n) x = color ^ (++y%2); //논리 비트연산
    if(y >= n) return;
    if (board[x][y] && !diagLeft[x+y] && !diagRight[x-y+n]) {
        diagLeft[x+y] = diagRight[x-y+n] = true;
        dfs(x+2, y, cnt+1);
        diagLeft[x+y] = diagRight[x-y+n] = false;
    }
    dfs(x+2, y, cnt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, 0, 0); color = 1;
    dfs(1, 0, 0);
    cout << ans[0]+ans[1] << '\n';
}

/*
 * 시간 단축을 위해 color = 0, 1 나눠서 백트래킹을 한다. 
 */

