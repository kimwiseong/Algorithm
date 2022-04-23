#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    string result = "";
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            result += '.';
            continue;
        }

        for (int j = i; j < s.length() && s[j] == 'X'; j++)
            cnt++;
        i += (cnt - 1);
        if (cnt % 2 != 0)
        {
            cout << -1 << "\n";
            return 0;
        }
        while (true)
        {
            if (cnt >= 4)
            {
                result += "AAAA";
                cnt -= 4;
            }
            else if (cnt == 2)
            {
                result += "BB";
                cnt -= 2;
            }
            else
                break;
        }
    }
    cout << result << "\n";
}