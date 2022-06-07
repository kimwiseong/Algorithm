/** dfs, graph */
#include<bits/stdc++.h>
using namespace std;
int N, M, a, b;
vector<vector<int>> v(2100);
bool vis[2100], ans = false;

void dfs(int x, int cnt) {
    if(cnt == 4) {
        ans = true;
        return;
    }
    vis[x] = true;
    for (int &nxt : v[x]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, cnt+1);
        vis[nxt] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    while(M--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        memset(vis, false, sizeof(vis));
        dfs(i, 0);
        if(ans) break;
    }

    cout << ans << '\n';
}