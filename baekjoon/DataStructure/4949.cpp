#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        stack<char> bk;
        string s = "";

        getline(cin, s);

        if (s == ".")
            break;

        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
                bk.push(s[i]);

            else if (s[i] == ')')
            {
                if (!bk.empty() && bk.top() == '(')
                    bk.pop();
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (!bk.empty() && bk.top() == '[')
                    bk.pop();
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (bk.empty() && flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}