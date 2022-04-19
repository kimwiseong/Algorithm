#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    int n, m, cnt = 0;
    cin >> n >> m;

    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    while (m--)
    {
        string str;
        cin >> str;
        if (s.find(str) != s.end())
            cnt++;
    }

    cout << cnt << "\n";
}