#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    queue<int> r;
    queue<char> op;

    int n, seq, i = 1;
    cin >> n;
    while (n--)
    {
        cin >> seq;
        r.push(seq);
    }

    while (!r.empty())
    {
        if (!s.empty() && s.top() == r.front())
        {
            s.pop();
            r.pop();
            op.push('-');
        }
        else if (i <= r.front())
        {
            while (i <= r.front())
            {
                s.push(i++);
                op.push('+');
            }
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }

    while (!op.empty())
    {
        cout << op.front() << "\n";
        op.pop();
    }
    return 0;
}