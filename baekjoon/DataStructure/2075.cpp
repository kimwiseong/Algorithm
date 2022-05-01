#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            pq.push(x);
            if ((int)pq.size() > n)
                pq.pop();
        }
    cout << pq.top() << "\n";
}