#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100];
bool visit[100];

void dfs(int x)
{
    visit[x] = true;
    // for (int i = 0; i < tree[x].size(); i++)
    //     if (!visit[tree[x][i]])
    //         dfs(tree[x][i]);

    //범위 기반 반복
    for (const int &next : tree[x])
        if (!visit[next])
            dfs(next);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, v1, v2;
    cin >> a >> b;

    while (b--)
    {
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    dfs(1);
    int result = 0;
    for (int i = 1; i <= a; i++)
        result += visit[i];

    cout << result - 1 << "\n";
}