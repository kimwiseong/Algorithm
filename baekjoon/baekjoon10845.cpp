#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    queue<int> q;
    int n, input;

    cin >> n;

    while (n--)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> input;
            q.push(input);
        }

        else if (cmd == "pop")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }

        else if (cmd == "size")
            cout << q.size() << "\n";

        else if (cmd == "empty")
            cout << q.empty() << "\n";

        else if (cmd == "front")
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";

        else if (cmd == "back")
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
    }
}