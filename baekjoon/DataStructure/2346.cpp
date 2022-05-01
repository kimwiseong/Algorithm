#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<pair<int, int>> dq;
    int n, bln;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bln;
        dq.push_back({i, bln});
    }
    while (!dq.empty())
    {
        cout << dq.front().first << " ";
        int a = dq.front().second;
        dq.pop_front();

        if (dq.empty())
            break;

        if (a > 0)
            for (a -= 1; a > 0; a--)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        else
            while (a++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
    }
    cout << "\n";
}