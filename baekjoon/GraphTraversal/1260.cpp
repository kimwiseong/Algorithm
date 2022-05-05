/* bfs, dfs */
#include <bits/stdc++.h>
using namespace std;

/* ** 이중 벡터로 graph구현 ** */
vector<vector<int>> graph(1001);
bool visit[1001];

void dfs(int x)
{
    visit[x] = true;
    cout << x << " ";
    for (const int &next : graph[x])
        if (!visit[next])
            dfs(next);
}

void bfs(int x)
{
    queue<int> q;
    visit[x] = true;
    q.push(x);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (const int &next : graph[cur])
        {
            if (!visit[next])
            {
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, V, u, v;
    cin >> N >> M >> V;
    while (M--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);
    cout << "\n";
    //배열 초기화
    memset(visit, false, sizeof(visit));
    bfs(V);
    cout << "\n";
    return 0;
}