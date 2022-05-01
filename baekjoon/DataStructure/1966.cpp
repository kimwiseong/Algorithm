#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m, imp;
    cin >> t;

    while (t--)
    {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> imp;
            pq.push(imp);
            q.push({i, imp});
        }
        while (!q.empty())
        {
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();
            if (value == pq.top())
            {
                cnt++;
                if (idx == m)
                    break;
                pq.pop();
                continue;
            }
            q.push({idx, value});
        }
        cout << cnt << "\n";
    }
}