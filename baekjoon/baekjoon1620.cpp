#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> num;
    map<int, string> name;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string pkm;
        cin >> pkm;
        num.insert({pkm, i});
        name.insert({i, pkm});
    }

    while (m--)
    {
        string find;
        cin >> find;
        if (isdigit(find[0]))
            cout << name[stoi(find)] << "\n";
        else
            cout << num[find] << "\n";
    }
}
