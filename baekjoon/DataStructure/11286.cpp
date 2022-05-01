#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // minheap - 자료형, 구조체, 비교연산자
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x == 0)
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        else
            pq.emplace(abs(x), x);
    }
}