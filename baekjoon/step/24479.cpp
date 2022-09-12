#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree[100001];
bool visit[100001];
int ans[100001];
int n, m, r;
int cnt = 0;

void dfs(int x) {
    if (visit[x]) return;
    visit[x] = true;
    ans[x] = ++cnt;
    for (int i = 0; i < tree[x].size(); i++)
        dfs(tree[x][i]);
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int v, u;
    cin >> n >> m >> r;

    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
		sort(tree[i].begin(), tree[i].end());
	}

    dfs(r);

    for (int i = 1; i <= n; i++) 
        cout << ans[i] << '\n';
}

