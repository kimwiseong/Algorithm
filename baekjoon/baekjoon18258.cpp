#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    //이 부분을 안쓰면 시간초과 뜸.
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> q;
    int n, input;
    string c;
    cin >> n;
    while (n--)
    {
        cin >> c;
        if (c == "push")
        {
            cin >> input;
            q.push(input);
        }

        else if (c == "pop")
            if (q.empty())
                cout << -1 << "\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }

        else if (c == "size")
            cout << q.size() << "\n";

        else if (c == "empty")
            cout << q.empty() << "\n";

        else if (c == "front")
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";

        else if (c == "back")
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";

        else
            break;
    }
}
