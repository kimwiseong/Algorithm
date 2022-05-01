#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;

int main(void)
{
    int result = 0, num = 1;
    cin >> str;

    if (str.length() % 2 == 1)
    {
        cout << result << "\n";
        return 0;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            num *= 2;
            s.push('(');
        }
        else if (str[i] == '[')
        {
            num *= 3;
            s.push('[');
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() == '[')
            {
                result = 0;
                break;
            }
            else if (str[i - 1] == '(')
            {
                result += num;
                num /= 2;
                s.pop();
            }
            else
            {
                num /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() == '(')
            {
                result = 0;
                break;
            }
            else if (str[i - 1] == '[')
            {
                result += num;
                num /= 3;
                s.pop();
            }
            else
            {
                num /= 3;
                s.pop();
            }
        }
    }

    cout << result << "\n";

    return 0;
}