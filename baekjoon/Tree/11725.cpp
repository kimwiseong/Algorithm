//노드 부모 찾기 - dfs 사용
#include <iostream>
#include <queue>
using namespace std;

vector<int> tree[100001];
int parent[100001];

void dfs(int v)
{
    for (int i = 0; i < tree[v].size(); i++)
    {
        if (parent[tree[v][i]] == 0)
        {
            parent[tree[v][i]] = v;
            dfs(tree[v][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
}