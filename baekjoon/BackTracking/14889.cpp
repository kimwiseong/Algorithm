/* backtracking, 스타트와 링크, 시간초과를 피하기 위해 nxt추가 */ 
#include<bits/stdc++.h>
using namespace std;
int n, ans = 100000, s[30][30]; 
bool vis[30];

void dfs(int x, int nxt) {
    if(x == n/2) {
        int start = 0, link = 0;
        for (int i = 0; i <= n; i++) 
            for (int j = 0; j <= n; j++) 
                if(vis[i] && vis[j]) start += s[i][j];
                else if(!vis[i] && !vis[j]) link += s[i][j];

        ans = ans > abs(start - link) ? abs(start - link) : ans;
        return;
    }

    for(int i = nxt; i < n; i++) {
        vis[i] = true;
        dfs(x+1, i+1);
        vis[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    
    dfs(0, 1);
    cout << ans << '\n';
}